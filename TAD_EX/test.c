#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Personn{
    char nom;
    char prenom;
    int age;
}Personn;

void addNom(Personn *p1){

    p1.nom = 'A';
    printf("%s", p1.nom);
    p1.prenom = 'O';
    printf("%s", p1.prenom);

}

typedef struct coordonnees{
    int x;
    int y;

}coordonnees;

void inialiserCoordonnees(coordonnees *point){

    (*point).x = 4;
    (*point).y = 7;
}

int main(){
    Personn p;
    addNom(&p);

    coordonnees monPoint;

    inialiserCoordonnees(&monPoint);

    //printf("Point x : %d", inialiserCoordonnees(&monPoint) );
    //printf("Point y : %d ", )

    return 0;
}
