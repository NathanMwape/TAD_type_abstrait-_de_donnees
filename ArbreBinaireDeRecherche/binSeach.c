// 1. KALUME NSENGA Yves
// 2. MPETI MWAPE Nathan
// 3. SANGWA MAYOMBO Fabrice

#include <stdlib.h>
#include <stdio.h>

#include "binSeach.h"


noeud *creerNoeud(int valeurN){

    noeud *Noeud= (noeud*) malloc(sizeof(noeud));
    Noeud -> valeur = valeurN;
    Noeud -> gauche = NULL;
    Noeud -> droit = NULL;

    return Noeud;
}

noeud *ajouterNouveuNoeud(noeud *nouveauNoeud, noeud *racine, noeud *pointeTemp){



    if (racine == NULL){

        return nouveauNoeud;

    }


    if (nouveauNoeud -> valeur == pointeTemp -> valeur){

        printf("\n%d est une valeur existante\nImpossible de l'ajouter a l'arbre ", nouveauNoeud -> valeur);

        return racine;

    }else if (nouveauNoeud -> valeur < pointeTemp -> valeur ){

        if (pointeTemp -> gauche == NULL){

            pointeTemp -> gauche = nouveauNoeud;

        }else{

            ajouterNouveuNoeud(nouveauNoeud,racine, pointeTemp -> gauche);

        }
    }else if (nouveauNoeud -> valeur > pointeTemp -> valeur){

        if (pointeTemp -> droit == NULL){

            pointeTemp -> droit = nouveauNoeud;

        }else{

            ajouterNouveuNoeud(nouveauNoeud, racine, pointeTemp -> droit);
        }
    }

    return racine;

}


noeud *ajouterNoeud(noeud *racine, int valeur){

    noeud *nouveauNoeud = creerNoeud(valeur);

    return ajouterNouveuNoeud(nouveauNoeud, racine, racine);

}



void rechercherValeur (noeud *racine, int valeurRec){

    if (racine -> valeur == valeurRec){

         printf("\n%d Existe", racine -> valeur);

    } else if (valeurRec < racine -> valeur){

        if (racine -> gauche != NULL){

            return rechercherValeur( racine -> gauche, valeurRec);

        } else {

            printf("\nN'existe pas dans l'arbre", racine -> gauche);
        }

    } else {

        if (racine -> droit != NULL){

            return rechercherValeur(racine -> droit, valeurRec );

        } else {

            printf("\nN'existe pas dans l'arbre");

        }

    }


}


void parcoursSuffixe(noeud *racine){


    printf("\n%d", racine -> valeur);

    if (racine -> gauche != NULL){
        parcoursSuffixe(racine -> gauche);
    }
    if (racine -> droit != NULL){
        parcoursSuffixe(racine -> droit);
    }

}

void parcoursInfixe(noeud *racine){

    if (racine -> gauche != NULL)
        parcoursInfixe(racine -> gauche);
    printf("\n%d", racine -> valeur);
    if (racine -> droit != NULL )
        parcoursInfixe(racine -> droit);
}


void parcoursPrefixe(noeud *racine){

    if (racine -> gauche != NULL)
        parcoursPrefixe(racine -> gauche);
    if (racine -> droit != NULL)
        parcoursPrefixe(racine -> droit);
    printf("\n%d", racine -> valeur);



}



