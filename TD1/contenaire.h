#include <stdbool.h>
#include "complex.h"
#define Dim 10 

typedef struct objet{
	Complex c; 
	bool b; 
} Objet;


Objet tab[Dim];

void createContenaire(Objet tab[], int n ); 
void ajoutContenaire(Objet tab[], int n, Complex c );
void supprimerContenaire(Objet tab[], int n , Complex  ob );
void detruireContenaire(Objet tab[], int n );
Complex  valeurContenaire(Objet tab[], int n );
void printContenaire(Objet tab[], int n );



