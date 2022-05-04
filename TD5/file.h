
typedef unsigned int nat;
typedef struct Cellule Cellule;
typedef Cellule *curseur;

struct Cellule {
    char val;
    curseur suivant;
    curseur precedant;
};

typedef struct ListeDBChaine ListeDBChaine;
typedef ListeDBChaine *ListDC;

struct ListeDBChaine {
    nat taille;
    curseur premier;
    curseur dernier;
    curseur cle;
} ;

/* STRUCTURE FILE & PRIMITIVES */
typedef ListeDBChaine *File;

char valeurFile(File f);
bool fileVide(File f);
bool filePleine(File f);
bool existeFile(File f);

File creerFile();
void enfiler(File f, char c);
void defiler(File f);
void detruireFile(File f);

/* END STRUCTURE FILE */

curseur creerCellule(char x);

ListDC creerListeDBChaine(void);

void debutListe(ListDC L);

void finListe(ListDC L);

void suivant(ListDC L);

void precedant(ListDC L);

int listeVide(ListDC L);

char valeur(ListDC L);

int taille(ListDC L);

curseur getCleListe(ListDC L);

void setCleListe(ListDC L, curseur p);

void insereEnTete(ListDC L, char  c);

void insereFin(ListDC L, char  c);

void insereApres(ListDC L, char  c);

void insereAvant(ListDC L, char  c);

void supprimeEnTete(ListDC L);

void supprimeFin(ListDC L);

void supprimeApres(ListDC L);

void supprimeAvant(ListDC L);

void afficherListe(ListDC L);

