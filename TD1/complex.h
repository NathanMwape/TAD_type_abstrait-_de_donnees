#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
//type abstrait complexe

typedef struct complex{
	double r; // real part
	double i; // imag part
}Complex;



Complex C_new (double r, double i);

Complex C_add (Complex a,  Complex b);

Complex C_mul (Complex a, Complex b);

double C_module (Complex a);


bool C_compare(Complex a, Complex b);

/* Fonction d'affichage d'un nombre complexe */

void C_print(Complex a);
