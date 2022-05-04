#include "listSC.h"

listSC maList(void){
    return NULL;
}

listSC push(listSC L, char c){

    liste *el;
    el = malloc(sizeof(*L));

    el->val = c;
    el->suiv = NULL;

    if(L == NULL){
        return el;
    }
    liste *T;
    T = L;
    while(T->suiv != NULL){
        T = T->suiv;
    }
    T->suiv = el;
    return L;

}
listSC unshift(listSC L, char c){
    liste *el;
    el = malloc(sizeof(*L));
    el->val = c;

    if(L == NULL){
        el->suiv = NULL;
    }
    else{
        el->suiv = L;
    }
    return el;
}

listSC pop(listSC L){
    if(L == NULL){

    }
    else if (L->suiv == NULL)
        L = NULL;

    liste *T = L;
    liste *avant = L;
    while(T->suiv != NULL){
        avant = T;
        T = T->suiv;
    }
    avant->suiv = NULL;
    T = NULL;
    return L;
}
listSC shift(listSC L){

    if(L == NULL){
        return L;
    }
    liste *el;
    el = malloc(sizeof(*el));
    el = L->suiv;
    L = NULL;
    return el;
}
void display(listSC L){
    if(L == NULL){
        printf("la liste est vide");
    }
    while(L != NULL){
        printf("%c ", L->val);
        L = L->suiv;
    }
}

int main(void) {

    listSC MaList = maList();

    MaList = push(MaList, 'A');
    MaList = push(MaList, 'B');
    MaList = push(MaList, 'C');
    MaList = push(MaList, 'D');
    MaList = push(MaList, 'E');

    MaList = shift(MaList);
    MaList = pop(MaList);
    MaList = push(MaList, 'F');

    display(MaList);

    return 0;
}

