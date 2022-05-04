#include "listTest.h"

Liste *inialisation(){
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL){
        printf("erreur d'allocation");
    }
    element->value = 0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

void insertion(Liste *liste, int vNombre){
    Element *nouveau = malloc(sizeof(*nouveau));

    nouveau->value = vNombre;

    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void afficher(Liste *L){

    Element *el = L->premier;
    while(el != NULL){
        printf("%d|", el->value);
        el = el->suivant;
    }

}

int main(void){

    Liste *li = inialisation();
    insertion(li, 7);
    insertion(li, 4);
    insertion(li, 1);
    insertion(li, 3);
    insertion(li, 14);

    afficher(li);
    return 0;

}
