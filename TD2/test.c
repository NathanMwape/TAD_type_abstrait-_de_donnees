#include "implTab_listeSC_car.h"

void creerListe(listSC *L)
{
    L->taille = 0;
    L->premier = NIL;
    L->cle = NIL;
    L->prLibre = 0;
    int i;
    for(i=1; i<=TAILLEMaX; i++)
    {
        Cellule c;
        c.idSuiv = i;
        L->tab[i-1] = c;
    }
    L->tab[TAILLEMaX-1].idSuiv = -1;
}

void debutListe(listSC *L)
{
    L->cle = L->premier;
}

void suivant(listSC *L)
{
    if(L->cle != NIL) {
        L->cle = L->tab[L->cle].idSuiv;
    }
}

int listeVide(listSC *L)
{
    return L->taille == 0;
}

char valeur(listSC *L)
{
    if(L->cle != NIL) {
        return L->tab[L->cle].val;
    }
    return '\0';
}

int taille(listSC *L)
{
    return L->taille;
}

curseur getCleListe(listSC *L)
{
    return L->cle;
}

void setCleListe(listSC *L, curseur p)
{
    L->cle = p;
}

curseur prendreCellule(listSC *L)
{
    curseur n;
    n = L->prLibre;
    L->prLibre = L->tab[L->prLibre].idSuiv;
    return n;
}

void insereEnTete(listSC *L, char  c)
{
    curseur prLibre = prendreCellule(L);
    curseur premier = L->premier;
    L->tab[prLibre].val = c;
    L->taille++;
    L->premier = prLibre;
    L->tab[premier].idSuiv = L->tab[prLibre].idSuiv;
    L->tab[prLibre].idSuiv = premier;
}

void insereApres(listSC *L, char  c)
{
    curseur prLibre = prendreCellule(L);
    L->tab[prLibre].val = c;
    L->taille++;
}

int listePleine(listSC *L)
{
    return L->taille == TAILLEMaX;
}

void supprimeEnTete(listSC *L)
{
    L->taille --;
    Cellule celluleSupprimee = L->tab[L->premier];
    curseur nouveauPremier = celluleSupprimee.idSuiv;
    curseur nbPrLibre = L->prLibre;
    L->premier = nouveauPremier;
    L->tab[L->prLibre].idSuiv = celluleSupprimee.idSuiv;
    celluleSupprimee.idSuiv = nbPrLibre;
}

int main(void) {

    listSC liste;
    creerListe(&liste);
    insereApres(&liste,'D');
    insereApres(&liste,'Y');
    insereEnTete(&liste,'A');
    insereApres(&liste,'M');
    suivant(&liste);
    insereApres(&liste,'B');
    insereEnTete(&liste,'C');
    insereEnTete(&liste,'B');
    insereApres(&liste,'M');
    suivant(&liste);
    suivant(&liste);
    suivant(&liste);
    printf("taille : %d \n", liste.taille);
    printf("premier : %d \n", liste.premier);
    printf("prLibre : %d \n", liste.prLibre);
    printf("cle : %d \n", liste.cle);
    return 0;
}
