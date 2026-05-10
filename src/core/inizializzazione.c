#include <stdlib.h>
#include <string.h>
#include "core/inizializzazione.h"

// inizializzazione lettere della parola
char *Lettere(char *parola) {
    char *letters = calloc(strlen(parola) + 1, sizeof(char));

    for (size_t i = 0; i < strlen(parola); ++i) {
        if (i == 0)
            letters[i] = parola[i];
        else
            letters[i] = ' ';
    }

    return letters;
}

// inizializzazione simboli per vocali e consonanti
char *Simboli(char *parola) {
    char *characters = calloc(strlen(parola) + 1, sizeof(char));

    for (size_t i = 0; i < strlen(parola); ++i) {
        // vocale '+'
        if ((parola[i] == 'a' || parola[i] == 'A') || (parola[i] == 'e' || parola[i] == 'E') || (
                parola[i] == 'i' || parola[i] == 'I') ||
            (parola[i] == 'o' || parola[i] == 'O') || (parola[i] == 'u' || parola[i] == 'U'))
            characters[i] = '+';

            // accento (non visibile)
        else if (parola[i] == '\'')
            characters[i] = ' ';

            // consonante '-'
        else
            characters[i] = '-';
    }

    return characters;
}

// inizializzazione lettere alfabetiche (disponibili)
char *Alfabeto() {
    char *alphabet = calloc(27, sizeof(char));

    for (size_t i = 0; i < 26; ++i)
        alphabet[i] = i + 97;

    return alphabet;
}
