#include "arbre.h"
#define NIL -1

bool arbreVide(AB *a){
}

char getValeur(sommet *n){
    return n->val;
}

sommet *filsGauche(sommet *n){
    return n->filsGauche;
}

sommet *filsDroit(sommet *n){
    return n->filsDroit;
}

sommet *pere(sommet *n){
    return n->pere;
}

ArbreBinaire *creerArbre(){
    AB->racine = NIL;
    AB->racine->filsGauche = NIL;
    AB->racine->filsDroit = NIL;
}

sommet *creerSommet(char c){
    AB sommet;
    return sommet->racine;
}

int main(){

    return 0;
}


