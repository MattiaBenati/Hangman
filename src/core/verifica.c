#include <string.h>
#include "core/verifica.h"

// verifica lettera
bool VerificaLettera(char* parola, char* lettera)
{
    for (size_t i = 0; i < strlen(parola); ++i)
    {
        if (parola[i] == lettera[0])
            return true;
    }

    return false;
}

// verifica parola
bool VerificaParola(char* parola, char* lettere)
{
    for (size_t i = 0; i < strlen(parola); ++i)
    {
        if (parola[i] != lettere[i])
            return false;
    }

    return true;
}