#ifndef INPUT_H
#define INPUT_H

#define MAX_INPUT 100

typedef enum {
    INPUT_OK,
    INPUT_ERROR,
    INPUT_EXIT
} InputResult;

void MaiuscMinusc(char *parola);

InputResult InputParola(char *input);

InputResult InputLettera(char *alfabeto, char *parola, char *input);

#endif //INPUT_H