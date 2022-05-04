#include <stdlib.h>
#include <stdio.h>
#include "tasMin.h"

void creerTas(TasMin *tm) {
    tm->positionLibre = 1;
}

void supprimerTas(TasMin *tm) {
    creerTas(tm);
}

char valeur(TasMin *tm) {
    return tm->tab[1];
}

void ajouter(TasMin *tm, char c) {
    int pos = tm->positionLibre;
    tm->tab[pos] = c;
    while(tm->tab[pos] < tm->tab[pos/2]) {
        char tmp = tm->tab[pos];
        tm->tab[pos] = tm->tab[pos/2];
        tm->tab[pos/2] = tmp;
        pos = pos/2;
    }
    tm->positionLibre ++;
}

void supprimer(TasMin *tm) {
    int pos = tm->positionLibre;
    if(pos > 1) {
        tm->tab[1] = tm->tab[pos-1];
        reorganiserDesc(tm, 1);
        tm->positionLibre --;
    }
}

void reorganiserDesc(TasMin *tm, int posParent) {
    char p = tm->tab[posParent];
    char fg = tm->tab[posParent * 2];
    char fd = tm->tab[posParent * 2 + 1];
    if(fg < fd && fg < p) {
        tm->tab[posParent * 2] = p;
        tm->tab[posParent] = fg;
        reorganiserDesc(tm, posParent * 2);
    } else if (fd < fg && fd < p) {
        tm->tab[posParent * 2 + 1] = p;
        tm->tab[posParent] = fd;
        reorganiserDesc(tm, posParent * 2 + 1);
    }
}

void afficherTas(TasMin *tm) {
    int i;
    for(i=1; i<tm->positionLibre; i++) {
        printf("%c ", tm->tab[i]);
    }
    printf("\n");
}

void afficherSuite(TasMin *tm, int fg, int fd) {
    if(fg < tm->positionLibre && fd < tm->positionLibre && tm->tab[fg] < tm->tab[fd]) {
        printf("%c ", tm->tab[fg]);
        afficherSuite(tm, fg * 2, fg * 2 + 1);
        printf("%c ", tm->tab[fd]);
        afficherSuite(tm, fd * 2, fd * 2 + 1);
    } else if(fd < tm->positionLibre && fg < tm->positionLibre && tm->tab[fd] < tm->tab[fg]) {
        printf("%c ", tm->tab[fd]);
        afficherSuite(tm, fd * 2, fd * 2 + 1);
        printf("%c ", tm->tab[fg]);
        afficherSuite(tm, fg * 2, fg * 2 + 1);
    } else if(fg < tm->positionLibre) {
        printf("%c ", tm->tab[fg]);
        afficherSuite(tm, fg * 2, fg * 2 + 1);
    } else if(fd < tm->positionLibre) {
        printf("%c ", tm->tab[fd]);
        afficherSuite(tm, fd * 2, fd * 2 + 1);
    }
}

int main() {
    TasMin e;
    TasMin *t;
    t = &e;

    creerTas(t);
    ajouter(t, 'F');
    afficherTas(t);
    ajouter(t, 'E');
    afficherTas(t);
    ajouter(t, 'C');
    afficherTas(t);
    ajouter(t, 'G');
    afficherTas(t);
    ajouter(t, 'B');
    afficherTas(t);
    ajouter(t, 'A');
    afficherTas(t);
    supprimer(t);
    afficherTas(t);
    supprimer(t);
    afficherTas(t);

    return 0;
}
