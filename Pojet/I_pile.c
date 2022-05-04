#include "p_plile.h"

bool pileVide(PILE *p){
    return p->tete == NIL;
}

bool pilePlein(PILE *p){
    return p->tete >= tailleMax - 1;
}

void creePile(PILE *P){
    P->taille = 0;
    P->tete = NIL;
}

void empiler(PILE *p, char c){
    if(pilePlein(p)){
            printf('\0');
    }else{
        p->tete++;
        p->tab[p->tete].val = c;
        p->taille++;
    }
}

char depiler(PILE *p){
    char c;
    if(pileVide(p))
        return '\0';
    else{
        c = p->tab[p->tete].val;
        p->tete--;
        p->taille--;
    }
    return c;
}

char valeurPile(PILE *p){
    return p->tab[p->tete].val;
}

void detruirePile(PILE *p){
    creePile(p);
}


void afficherPile(PILE *p){
    int i;
    if(pileVide(p))
        printf("La pile est vide!");

    for(i = p->tete; i >= 0; i--){
        printf(" %c ", p->tab[i]);
    }
    printf("\n");
}
