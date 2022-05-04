#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TAILLEMaX  15
#define NIL -1

typedef int curseur;

typedef struct cellule{
  char val;
  curseur idSuiv;
} Cellule;

typedef struct listSC{
  int taille;
  Cellule tab[TAILLEMaX];
  curseur premier;
  curseur cle;
  curseur prLibre;
}listSC;

/*  IMPLEMENTATION DES PRIMITIVES PAR TABLEAU STATIQUE */

void debutListe(listSC *L);

void suivant(listSC *L);

int listeVide(listSC *L);

char valeur(listSC *L);

int taille(listSC *L);

curseur getCleListe(listSC *L);

void setCleListe(listSC *L, curseur p);

curseur prendreCellule(listSC *L);

void rendreCelluleA(listSC *L, curseur p );

void rendreCelluleP(listSC *L, curseur p );

void insereEnTete(listSC *L, char  c);

void insereApres(listSC *L, char  c);

int listePleine(listSC *L);

void supprimeEnTete(listSC *L);

void supprimeApres(listSC *L);

void creerListe(listSC *L);

/*   FIN      DE PRIMITIVES       */

