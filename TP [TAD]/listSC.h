#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TAILLEMaX  15
#define NIL -1

typedef struct liste{
    char val;
    struct liste *suiv;
}liste, *listSC;

listSC push(listSC L, char c);
listSC unshift(listSC L, char c);
listSC pop(listSC L);
listSC shift(listSC L);
void display(listSC L);

