#include <stdbool.h>

typedef struct Noeud {
    char val;
    Noeud *filsGauche;
    Noeud *filsDroit;
    Noeud *pere;
} Noeud;

struct ArbreBinaire {
    Noeud *racine;
};
typedef ArbreBinaire AB;

bool arbreVide(AB *a);
char getValeur(Noeud *n);
Noeud *filsGauche(Noeud *n);
Noeud *filsDroit(Noeud *n);
Noeud *pere(Noeud *n);
bool estFeuille(Noeud *n);
AB *creerArbre();
Noeud *creerSommet(char c);
void setValeur(Noeud *n, char c);
void ajouterFilsGauche(AB *a, char c);
void ajouterFilsDroit(AB *a, char c);
void supprimerFilsGauche(AB *a);
void supprimerFilsDroit(AB *a);
void detruireSommet(Noeud *n);
