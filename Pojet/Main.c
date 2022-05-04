#include "I_pile.c"

int main(){
    PILE B;
    creePile(&B);
    empiler(&B,'N');
    empiler(&B,'T');
    printf("Taille de la pile : %d\n", B.taille);
    printf("Indice en tete : %d\n", B.tete);
    printf("La Valeur en tete : %c\n\n", B.tab[B.tete].val);


    empiler(&B, 'J');
    empiler(&B,'O');
    //afficherPile(&B);
    printf("Taille de la pile : %d\n", B.taille);
    printf("Indice en tete : %d\n", B.tete);
    printf("La Valeur en tete : %c\n\n", B.tab[B.tete].val);
    //On depile
    printf("La Valeur Depiler : %c\n", depiler(&B));
    //afficherPile(&B);
    printf("Taille de la pile : %d\n", B.taille);
    printf("Indice en tete : %d\n", B.tete);
    printf("La Valeur en tete : %c\n\n", valeurPile(&B));
    afficherPile(&B);
    detruirePile(&B);
    printf("destruction de la pile \nTaille de la pile : %d\n", B.taille);
    printf("Indice en tete : %d\n", B.tete);
    afficherPile(&B);
    return 0;
}
