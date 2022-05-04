#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "file.h"

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

void insereEnTete(ListDC L, char  c) {
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

void supprimeEnTete(ListDC L) {
    if(!listeVide(L)) {
        L->premier = L->premier->suivant;
        L->premier->precedant = NULL;
        L->taille --;
    }
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

char valeurFile(File f) {
    debutListe(f);
    return valeur(f);
}

bool fileVide(File f) {
    return listeVide(f);
}
bool filePleine(File f) {

}
bool existeFile(File f) {
    return f != NULL;
}

File creerFile() {
    return creerListeDBChaine();
}
void enfiler(File f, char c) {
    insereFin(f, c);
}
void defiler(File f) {
    supprimeEnTete(f);
}
void detruireFile(File f) {
    f = NULL;
}

int compterOccurrence(File f, char c) {
    enfiler(f, '\0');
    char r = valeurFile(f);
    int comp = 0;
    while(r != '\0') {
        defiler(f);
        if(r == c)
            comp++;
        enfiler(f, r);
        r = valeurFile(f);
    }
    defiler(f);

    return comp;
}

void supprimerOccurrenceSaufFirst(File f, char c) {
    enfiler(f, '\0');
    char tmp = valeurFile(f);
    int compteur = 0;
    while(tmp != '\0') {
        if(tmp == c) {
            if(compteur == 0) {
                compteur ++;
                defiler(f);
                enfiler(f, tmp);
            } else {
                defiler(f);
            }
        } else {
            defiler(f);
            enfiler(f, tmp);
        }
        tmp = valeurFile(f);
    }
    defiler(f);
}

int main(void) {
    File t = creerFile(t);
    enfiler(t, 'K');
    enfiler(t, 'B');
    enfiler(t, 'K');
    enfiler(t, 'c');
    enfiler(t, 'K');
    enfiler(t, 'Y');
    printf("%d\n", compterOccurrence(t, 'K'));
    supprimerOccurrenceSaufFirst(t, 'K');
    printf("%d\n", compterOccurrence(t, 'K'));
    return 0;
}
