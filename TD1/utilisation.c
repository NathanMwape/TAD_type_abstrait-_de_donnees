#include "complex.h"
#include "contenaire.h"
#define Dim 10 

int main(void){
  Objet tab[Dim];
  Complex c1,c2;
  double r1,r2;
  createContenaire(tab, Dim);
  printContenaire(tab, Dim);
  ajoutContenaire(tab, Dim , c1);
  ajoutContenaire(tab, Dim , c2);
  printContenaire(tab, Dim);
  ajoutContenaire(tab, Dim , C_new(1.,1. ));
  ajoutContenaire(tab, Dim , C_new(1.,-2. ));
  ajoutContenaire(tab, Dim , C_new(3.,-1. ));
  ajoutContenaire(tab, Dim , C_new(3.,-1. ));
  printContenaire(tab, Dim);
  supprimerContenaire(tab, Dim , C_new(1.,1. ));
  c1=valeurContenaire(tab, Dim);
  c2=valeurContenaire(tab,Dim);
  c1=C_add(c1,c2);
  ajoutContenaire(tab,Dim, c1);
  printContenaire(tab, Dim);
  
  return EXIT_SUCCESS;
 
}
