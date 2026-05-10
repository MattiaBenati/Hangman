#ifndef GRAFICA_H
#define GRAFICA_H
#define X_HOME 64
#define Y_HOME 13
#define X_GAME 100
#define Y_GAME 30
#include <stdbool.h>

void GoToXY(int x, int y);

void BordiPannelloGioco();

void BordiPannelloInizio();

void Istruzioni(int x, int y);

void Uscita(bool verif_par, char *parola);

#endif //GRAFICA_H
