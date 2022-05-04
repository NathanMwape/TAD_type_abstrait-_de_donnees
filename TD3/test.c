#include <stdlib.h>
#include <stdio.h>
#include "listeDC.h"

curseur creerCellule(char x) {
    curseur c = (curseur) malloc(sizeof(Cellule));
    if(c != NULL) {
        c->val = x;
        c->suivant = NULL;
        c->precedant = NULL;
        return c;
    } else {
        return NULL;
    }
}

ListDC creerListeDBChaine(void) {
    ListDC l = (ListDC) malloc(sizeof(ListeDBChaine));
    if(l != NULL) {
        l->taille = 0;
        l->premier = NULL;
        l->dernier = NULL;
        l->cle = NULL;
        return l;
    } else {
        return NULL;
    }
}

void debutListe(ListDC L) {
    L->cle = L->premier;
}

void finListe(ListDC L) {
    L->cle = L->dernier;
}

void suivant(ListDC L) {
    if(L->cle->suivant != NULL)
        L->cle = L->cle->suivant;
}

void precedant(ListDC L) {
    if(L->cle->precedant != NULL)
        L->cle = L->cle->precedant;
}

int listeVide(ListDC L) {
    return L->premier == NULL;
}

char valeur(ListDC L) {
    return (listeVide(L) ? '\0' : L->cle->val);
}

int taille(ListDC L) {
    return L->taille;
}

curseur getCleListe(ListDC L) {
    return L->cle;
}

void setCleListe(ListDC L, curseur p) {
    L->cle = p;
}

void insereEnTete(ListDC L, char c) {
    curseur cel = creerCellule(c);

    if(L->taille == 0) {
        L->dernier = cel;
    } else {
        curseur ancienPremier = L->premier;
        cel->suivant = ancienPremier;
        ancienPremier->precedant = cel;
    }
    L->premier = cel;
    debutListe(L);
    L->taille ++;
}

void insereFin(ListDC L, char  c) {
    curseur cel = creerCellule(c);

    if(L->taille == 0) {
        L->premier = cel;
    } else {
        curseur ancienDernier = L->dernier;
        cel->precedant = ancienDernier;
        ancienDernier->suivant = cel;
    }

    L->dernier = cel;
    finListe(L);
    L->taille ++;
}

void afficherListe(ListDC L) {
    debutListe(L);
    while(L->cle != NULL) {
        printf("%c ", valeur(L));
        L->cle = L->cle->suivant;
    }
    printf("\n");
    finListe(L);
}

int main(void) {
    ListDC t = creerListeDBChaine();
    insereFin(t, 'A');
    insereFin(t, 'B');
    insereFin(t, 'C');
    precedant(t);
    precedant(t);
    suivant(t);
    afficherListe(t);
    return 0;
}
