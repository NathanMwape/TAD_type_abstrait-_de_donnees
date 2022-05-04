#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define tailleMax 15
#define NIL -1


//typedef int curseur;

typedef struct cellule{
  char val;
} Cellule;

typedef struct pile{
  int tete;
  int taille;
  Cellule tab[tailleMax];
}PILE ;

char valeurPile(PILE *p);
void creePile(PILE *P);
void empiler(PILE *p, char c);
bool pileVide(PILE *p);
bool pilePlien(PILE *p);
char depiler(PILE *p);
void detruirePile(PILE *p);
void afficherPile(PILE *p);
