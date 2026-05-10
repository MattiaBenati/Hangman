#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "ui/console.h"
#include "core/input.h"
#include "core/inizializzazione.h"
#include "core/aggiornamento.h"
#include "core/verifica.h"
#include "../../include/ui/disegno.h"
#include "../../include/ui/grafica.h"
#include "core/gioco.h"
#define MODE_INIZIO "MODE 64, 13"
#define MODE_GIOCO  "MODE 100, 30"
#define MAX_ERRORI 7

static void DisegnaSchermataInizio(void) {
    system(MODE_INIZIO);
    CentraEBloccaFinestraConsole();

    BordiPannelloInizio();
    Istruzioni(3, Y_HOME - 6);
}

static void DisegnaSchermataGioco(size_t errori, char *alfabeto, char *lettere, char *simboli) {
    system(MODE_GIOCO);
    CentraEBloccaFinestraConsole();

    BordiPannelloGioco();
    Istruzioni(X_GAME / 2 + 3, Y_GAME - 7);

    StampaDisegno(errori, X_GAME / 4 - 25 / 2, 3);
    StampaAlfabeto(alfabeto);
    StampaLettere(lettere, simboli);
}

static void LiberaMemoriaPartita(char *alfabeto, char *lettere, char *simboli) {
    free(alfabeto);
    free(lettere);
    free(simboli);
}

void AvviaPartita(void) {
    while(1) {
        bool letteraCorretta = false;
        bool parolaIndovinata = false;
        size_t numeroErrori = 0;

        char parola[MAX_INPUT];

        while(1) {
            DisegnaSchermataInizio();

            InputResult risultatoParola = InputParola(parola);

            if(risultatoParola == INPUT_EXIT)
                return;

            if(risultatoParola == INPUT_OK)
                break;
        }

        char *alfabeto = Alfabeto();
        char *lettere = Lettere(parola);
        char *simboli = Simboli(parola);

        do {
            char lettera[MAX_INPUT];

            while(1) {
                DisegnaSchermataGioco(numeroErrori, alfabeto, lettere, simboli);

                InputResult risultatoLettera = InputLettera(alfabeto, parola, lettera);

                if(risultatoLettera == INPUT_EXIT) {
                    LiberaMemoriaPartita(alfabeto, lettere, simboli);
                    return;
                }

                if(risultatoLettera == INPUT_OK)
                    break;
            }

            if(strlen(lettera) == 1) {
                AggiornamentoLettere(parola, lettere, lettera);
                AggiornamentoAlfabeto(alfabeto, lettera);

                letteraCorretta = VerificaLettera(parola, lettera);

                if(letteraCorretta)
                    parolaIndovinata = VerificaParola(parola, lettere);
            } else {
                MaiuscMinusc(lettera);

                parolaIndovinata = VerificaParola(parola, lettera);
                letteraCorretta = parolaIndovinata;

                if(letteraCorretta) {
                    AggiornamentoLettere(parola, lettere, lettera);
                    AggiornamentoAlfabeto(alfabeto, lettera);
                }
            }

            if(!letteraCorretta)
                numeroErrori += 1;

            system("cls");
        } while(!parolaIndovinata && numeroErrori != MAX_ERRORI);

        DisegnaSchermataGioco(numeroErrori, alfabeto, lettere, simboli);
        Uscita(parolaIndovinata, parola);

        LiberaMemoriaPartita(alfabeto, lettere, simboli);
    }
}