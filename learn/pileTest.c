#include "pileT.h"


Pile *creerPile(){
    Pile *pile = malloc(sizeof(*pile));
    Cellule *cellule = malloc(sizeof(*cellule));

    cellule->value = 0;
    cellule->next = NULL;
    pile->premier = cellule;

    return pile;
}


void empiler(Pile *P, int x){
    Cellule *cel = malloc(sizeof(*cel));

    cel->value = x;
    cel->next = P->premier;
    P->premier = cel;
}

void affichage(Pile *P){

    Cellule *cel = P->premier;
    while (cel != NULL){
        printf("%d ", cel->value);
        cel = cel->next;
    }
}

int main(){

    Pile *pile = creerPile();

    empiler(pile, 7);
    empiler(pile, 4);
    empiler(pile, 8);

    affichage(pile);

    return 0;
}
