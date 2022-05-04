#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>


typedef struct complex{
	double r;
	double i;
}Complex;

Complex C_new(double r, double i);
Complex C_new(double r, double i)
{
    Complex t;
    t.r = r;
    t.i = i;
    return t;
}

Complex C_add (Complex a,  Complex b);
Complex C_add (Complex a,  Complex b)
{
    Complex c;
    c.r = a.r + b.r;
    c.i = a.i + b.i;
    return c;
}

Complex C_mul (Complex a, Complex b);
Complex C_mul (Complex a, Complex b)
{
    Complex m;
    m.r = a.r * b.i;
    m.i = a.i * b.r;
    return m;
}

double C_module (Complex a);
double C_module (Complex a)
{
    double res, i, r, s;
    i = pow(a.r, 2);
    r = pow(a.i, 2);
    s = i + r;
    res = sqrt(s);
    return res;
}

void c_display(Complex c);
void c_display(Complex c)
{
    printf("r : %.1f\n", c.r);
    printf("i : %.1f\n", c.i);
    printf("-------------\n");
}

bool C_compare(Complex a, Complex b);
bool C_compare(Complex a, Complex b)
{
    return a.r == b.r && a.i == b.i;
}

#define Dim 10

typedef struct objet{
	Complex c;
	bool b;
} Objet;

void createContenaire(Objet tab[], int n );
void createContenaire(Objet tab[], int n )
{
    int i;
    for(i=0; i<n; i++)
        tab[i].b = false;
}

void ajoutContenaire(Objet tab[], int n, Complex c );
void ajoutContenaire(Objet tab[], int n, Complex c )
{
    int i;
    for(i=0; i<n; i++)
    {
        if(!tab[i].b)
        {
            tab[i].c = c;
            tab[i].b = true;
            break;
        }
    }
}

void supprimerContenaire(Objet tab[], int n , Complex  ob );
void supprimerContenaire(Objet tab[], int n , Complex  ob )
{
    int i;
    for(i=0; i<n; i++)
    {
        if(C_compare(tab[i].c, ob))
        {
            tab[i].b = false;
            break;
        }
    }
}
void detruireContenaire(Objet tab[], int n );
void detruireContenaire(Objet tab[], int n )
{
    int i;
    for(i=0; i<n; i++)
    {
        tab[i].b = false;
    }
}
Complex valeurContenaire(Objet tab[], int n );
Complex valeurContenaire(Objet tab[], int n )
{
    Complex c;
    int i;
    for(i=0; i<n; i++)
    {
        if(tab[i].b)
        {
            c = tab[i].c;
            break;
        }
    }
    return c;
}
void printContenaire(Objet tab[], int n );
void printContenaire(Objet tab[], int n )
{
    int i;
    for(i=0; i<n; i++)
    {
        if(tab[i].b)
        {
            c_display(tab[i].c);
        }
    }
}


int main()
{

    return 0;
}



