#include <string.h>
#include "core/aggiornamento.h"

// aggiornamento lettere inserite dall'utente
void AggiornamentoLettere(char* parola, char* lettere, char* lettera)
{
    size_t length = strlen(parola) - 1;

    for (size_t i = 0; i < strlen(lettera); ++i)
    {
        for (size_t j = 0; j < strlen(parola); ++j)
        {
            if (parola[j] == lettera[i])
                lettere[j] = lettera[i];
        }

        if (parola[length] == '\'' && parola[length - 1] == lettera[i])
            lettere[length] = '\'';
    }
}

// aggiornamento lettere alfabeto inserite dall'utente
void AggiornamentoAlfabeto(char* alfabeto, char* lettera)
{
    for (size_t i = 0; i < strlen(lettera); ++i)
    {
        for (size_t j = 0; j < 26; ++j)
        {
            if (alfabeto[j] == lettera[i])
            {
                alfabeto[j] = ' ';
                break;
            }
        }
    }
}