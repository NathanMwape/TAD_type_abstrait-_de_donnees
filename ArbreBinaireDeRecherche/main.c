#include <stdio.h>
#include <stdlib.h>


#include "binSeach.c"


int main(){

   noeud *arbre;
   arbre = creerNoeud(8);
   ajouterNoeud(arbre, 10);
   ajouterNoeud(arbre, 3);

   ajouterNoeud(arbre, 1);
   ajouterNoeud(arbre, 6);
   ajouterNoeud(arbre, 4);
   ajouterNoeud(arbre, 7);
   ajouterNoeud(arbre, 14);
   ajouterNoeud(arbre, 13);
   ajouterNoeud(arbre, 0);
   ajouterNoeud(arbre, 15);
   ajouterNoeud(arbre, 15);


   printf("\nParcours Prefixe :");
   printf("\n---------------");
   parcoursPrefixe(arbre);

   printf("\nParcours Infixe :");
   printf("\n---------------");
   parcoursInfixe(arbre);

   printf("\nParcours Suffixe :");
   printf("\n---------------");
   parcoursSuffixe(arbre);


 //  rechercherValeur(arbre,15);




}


