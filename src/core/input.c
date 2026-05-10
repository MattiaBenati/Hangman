#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "core/input.h"
#include "ui/grafica.h"

// conversione formato parola
void MaiuscMinusc(char *parola) {
    size_t len = strlen(parola);

    for(size_t i = 0; i < len; ++i) {
        if(i == 0)
            parola[i] = toupper((unsigned char)parola[i]);
        else
            parola[i] = tolower((unsigned char)parola[i]);
    }
}

// input parola da indovinare
InputResult InputParola(char *input) {
    GoToXY(5, 3);
    printf("Inserisci la parola da indovinare: ");
    scanf("%99s", input);

    if(input[0] == '0')
        return INPUT_EXIT;

    size_t len = strlen(input);

    if(len == 1)
        return INPUT_ERROR;

    for(size_t i = 0; i < len; ++i) {
        if(!isalpha((unsigned char)input[i]) && input[i] != '\'')
            return INPUT_ERROR;
    }

    MaiuscMinusc(input);

    return INPUT_OK;
}

// input lettera/parola durante il gioco
InputResult InputLettera(char *alfabeto, char *parola, char *input) {
    GoToXY(X_GAME / 4 * 3 - 15, 15);
    printf("Inserisci una lettera/parola:");

    GoToXY(X_GAME / 4 * 3 - strlen(parola) / 2, 17);
    scanf("%99s", input);

    if(input[0] == '0')
        return INPUT_EXIT;

    size_t len = strlen(input);

    for(size_t i = 0; i < len; ++i)
        input[i] = tolower((unsigned char)input[i]);

    for(size_t i = 0; i < len; ++i) {
        if(!isalpha((unsigned char)input[i]) && input[i] != '\'')
            return INPUT_ERROR;
    }

    if(len == 1) {
        bool check = false;

        for(size_t i = 0; i < 26; ++i) {
            if(input[0] == alfabeto[i]) {
                check = true;
                break;
            }
        }

        if(check == false)
            return INPUT_ERROR;
    }

    return INPUT_OK;
}