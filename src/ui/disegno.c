#include <stdio.h>
#include <string.h>
#include "ui/disegno.h"
#include "ui/grafica.h"

// creazione disegno
static void Errore1(size_t x, size_t y) {
    GoToXY(x + 0, y + 18);
    printf("\"\"\"\"\"\"\"\"\"\"|_        |\"\"\"|");

    GoToXY(x + 0, y + 19);
    printf("|\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|");

    GoToXY(x + 0, y + 20);
    printf("| |        \\ \\        | |");

    GoToXY(x + 0, y + 21);
    printf(": :         \\ \\       : :");

    GoToXY(x + 0, y + 22);
    printf(". .          `'       . .");
}

static void Errore2(size_t x, size_t y) {
    Errore1(x, y);

    GoToXY(x + 0, y + 0);
    printf(" ___________.._______");

    GoToXY(x + 0, y + 1);
    printf("| .__________))______|");

    GoToXY(x + 0, y + 2);
    printf("| | / /      ||");

    GoToXY(x + 0, y + 3);
    printf("| |/ /       ||");

    GoToXY(x + 0, y + 4);
    printf("| | /        ||");

    GoToXY(x + 0, y + 5);
    printf("| |/");

    for (size_t i = 0; i < 12; ++i) {
        GoToXY(x + 0, y + 6 + i);
        printf("| |");
    }
}

static void Errore3(size_t x, size_t y) {
    Errore2(x, y);

    GoToXY(x + 15, y + 4);
    printf(".-''.");

    GoToXY(x + 13, y + 5);
    printf("|/  _  \\");

    GoToXY(x + 13, y + 6);
    printf("||  `/,|");

    GoToXY(x + 13, y + 7);
    printf("(\\\\`_.'");

    GoToXY(x + 12, y + 8);
    printf(".-`--'.");

    GoToXY(x + 12, y + 9);
    printf("Y . . Y");

    GoToXY(x + 13, y + 10);
    printf("|   |");

    GoToXY(x + 13, y + 11);
    printf("| . |");

    GoToXY(x + 13, y + 12);
    printf("|   |");
}

static void Errore4(size_t x, size_t y) {
    Errore3(x, y);

    GoToXY(x + 11, y + 9);
    printf("/");

    GoToXY(x + 10, y + 10);
    printf("//");

    GoToXY(x + 9, y + 11);
    printf("//");

    GoToXY(x + 8, y + 12);
    printf("')");
}

static void Errore5(size_t x, size_t y) {
    Errore4(x, y);

    GoToXY(x + 19, y + 9);
    printf("\\");

    GoToXY(x + 19, y + 10);
    printf("\\\\");

    GoToXY(x + 20, y + 11);
    printf("\\\\");

    GoToXY(x + 21, y + 12);
    printf("(`");
}

static void Errore6(size_t x, size_t y) {
    Errore5(x, y);

    for (size_t i = 0; i < 4; ++i) {
        GoToXY(x + 13, y + 13 + i);
        printf("||");
    }

    GoToXY(x + 12, y + 17);
    printf("/ |");

    GoToXY(x + 12, y + 18);
    printf("`-'");
}

static void Errore7(size_t x, size_t y) {
    Errore6(x, y);

    for (size_t i = 0; i < 4; ++i) {
        GoToXY(x + 16, y + 13 + i);
        printf("||");
    }

    GoToXY(x + 16, y + 17);
    printf("| \\");

    GoToXY(x + 16, y + 18);
    printf("`-'");

    GoToXY(x + 15, y + 13);
    printf("'");
}

// stampa disegno
void StampaDisegno(size_t errori, size_t x, size_t y) {
    switch (errori) {
        case 1:
            Errore1(x, y);
            break;
        case 2:
            Errore2(x, y);
            break;
        case 3:
            Errore3(x, y);
            break;
        case 4:
            Errore4(x, y);
            break;
        case 5:
            Errore5(x, y);
            break;
        case 6:
            Errore6(x, y);
            break;
        case 7:
            Errore7(x, y);
            break;
        default:
            break;
    }
}

// stampa lettere alfabetiche
void StampaAlfabeto(char *alfabeto) {
    GoToXY(X_GAME / 4 * 3 - strlen(alfabeto) / 2, 4);

    for (size_t i = 0; i < 13; ++i) {
        if (i != 12)
            printf("%c ", alfabeto[i]);
        else
            printf("%c", alfabeto[i]);
    }

    GoToXY(X_GAME / 4 * 3 - strlen(alfabeto) / 2, 6);

    for (size_t i = 13; i < 26; ++i) {
        if (i != 25)
            printf("%c ", alfabeto[i]);
        else
            printf("%c", alfabeto[i]);
    }
}

// stampa lettere rimanenti
void StampaLettere(char *lettere, char *simboli) {
    // stampa lettere (sopra)
    GoToXY(X_GAME / 4 * 3 - strlen(lettere), 12);

    for (size_t i = 0; i < strlen(lettere); ++i) {
        if (lettere[i + 1] == '\'')
            printf("%c", lettere[i]);
        else
            printf("%c ", lettere[i]);
    }

    // stampa simboli (sotto)
    GoToXY(X_GAME / 4 * 3 - strlen(lettere), 13);

    for (size_t i = 0; i < strlen(simboli); ++i) {
        printf("%c ", simboli[i]);
    }
}
