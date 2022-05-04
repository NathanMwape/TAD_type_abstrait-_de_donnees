#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Cellule{
    int value;
    Cellule *next;
}Cellule;

typedef struct Pile{
    Cellule *premier;
}Pile;
