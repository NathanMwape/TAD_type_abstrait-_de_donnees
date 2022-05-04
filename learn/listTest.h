#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TAILLEMaX  15
#define NIL -1

typedef struct Element{
    int value;
    struct Element *suivant;
}Element;


typedef struct Liste{
    Element *premier;
}Liste;

Liste *initialisation();
void insertionAfter();



