#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "ui/grafica.h"

// posizione specifica nello schermo
void GoToXY(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// stampa del pannello schermata iniziale
void BordiPannelloInizio() {
    // prima riga
    GoToXY(1, 1);
    printf("%c", 201);

    for (size_t i = 0; i < X_HOME - 4; ++i)
        printf("%c", 205);

    GoToXY(X_HOME - 2, 1);
    printf("%c", 187);

    // righe centrali
    for (size_t i = 0; i < Y_HOME - 4; ++i) {
        // colonna sinistra
        GoToXY(1, i + 2);
        printf("%c", 186);

        // colonna destra
        GoToXY(X_HOME - 2, i + 2);
        printf("%c", 186);
    }

    // separatore in alto (orizzontale)
    GoToXY(3, 5);

    for (size_t i = 0; i < X_HOME - 6; ++i)
        printf("%c", 196);

    // ultima riga
    GoToXY(1, Y_HOME - 2);
    printf("%c", 200);

    for (size_t i = 0; i < X_HOME - 4; ++i)
        printf("%c", 205);

    GoToXY(X_HOME - 2, Y_HOME - 2);
    printf("%c", 188);
}

// stampa del pannello schermata home
void BordiPannelloGioco() {
    // prima riga
    GoToXY(1, 1);
    printf("%c", 201);

    for (size_t i = 0; i < X_GAME - 4; ++i)
        printf("%c", 205);

    GoToXY(X_GAME - 2, 1);
    printf("%c", 187);

    // righe centrali
    for (size_t i = 0; i < Y_GAME - 4; ++i) {
        // colonna sinistra
        GoToXY(1, i + 2);
        printf("%c", 186);

        // colonna destra
        GoToXY(X_GAME - 2, i + 2);
        printf("%c", 186);
    }

    // separatore (verticale)
    for (size_t i = 0; i < Y_GAME - 6; ++i) {
        GoToXY(X_GAME / 2, i + 3);
        printf("%c", 179);
    }

    // separatore in alto (orizzontale)
    GoToXY(X_GAME / 2 + 2, 9);

    for (size_t i = 0; i < X_GAME / 2 - 5; ++i)
        printf("%c", 196);

    // separatore in basso (orizzontale)
    GoToXY(X_GAME / 2 + 2, Y_GAME - 10);

    for (size_t i = 0; i < X_GAME / 2 - 5; ++i)
        printf("%c", 196);

    // ultima riga
    GoToXY(1, Y_GAME - 2);
    printf("%c", 200);

    for (size_t i = 0; i < X_GAME - 4; ++i)
        printf("%c", 205);

    GoToXY(X_GAME - 2, Y_GAME - 2);
    printf("%c", 188);
}

// stampa istruzioni rapide
void Istruzioni(int x, int y) {
    GoToXY(x, y);
    printf("- Inserisci '0' se vuoi uscire dal gioco");

    GoToXY(x, y + 2);
    printf("- Il numero massimo di errori e' 7");
}

// uscita dal gioco
void Uscita(bool verif_par, char *parola) {
    // parola indovinata
    if (verif_par == true) {
        GoToXY(X_GAME / 4 * 3 - 21, 15);
        printf("Complimenti, era proprio questa la parola!");
    }

    // parola NON indovinata
    else {
        GoToXY(X_GAME / 4 * 3 - 15 - strlen(parola) / 2, 15);
        printf("Mi dispiace, la parola era '%s'", parola);
    }

    GoToXY(X_GAME / 4 * 3 - 20, 17);
    printf("Premi 'Invio' per continuare a giocare..");

    getchar();
    getchar();
}
