#include <stdlib.h>
#include <stdio.h>
#include "hpile.h"

Pile *initialisation(){
    Pile *pile = malloc(sizeof(*pile));
    Element *element = malloc(sizeof(*element));
    if (pile == NULL || element == NULL){
        exit(EXIT_FAILURE);
    }
    element->nombre = 0;
    element->suivant = NULL;
    pile->premier = element;
    return pile;
}

void empiler(Pile *pile, int nvNombre){
    Element *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL){
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}

int depiler(Pile *pile){
    if (pile == NULL){
        exit(EXIT_FAILURE);
    }
    int nombreDepile = 0;
    Element *elementDepile = pile->premier;
    if (pile != NULL && pile->premier != NULL){
        nombreDepile = elementDepile->nombre;
        pile->premier = elementDepile->suivant;
        free(elementDepile);
    }
    return nombreDepile;
}

void afficherPile(Pile *pile){
    if (pile == NULL){
        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;
    while (actuel != NULL){
        printf("%d\n", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("\n");
}
int main(){
    Pile *maPile = initialiser();
    empiler(maPile, 4);
    empiler(maPile, 8);
    empiler(maPile, 15);
    empiler(maPile, 16);
    empiler(maPile, 23);
    empiler(maPile, 42);
    printf("\nEtat de la pile :\n");
    afficherPile(maPile);
    printf("Je depile %d\n", depiler(maPile));
    printf("Je depile %d\n", depiler(maPile));
    printf("\nEtat de la pile :\n");
    afficherPile(maPile);
    return 0;
}
