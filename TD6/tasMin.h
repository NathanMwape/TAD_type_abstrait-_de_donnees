
#define N 30

typedef struct TasMin {
    int positionLibre;
    char tab[N];
} TasMin;

char valeur(TasMin *tm);
void ajouter(TasMin *tm, char c);
void supprimer(TasMin *tm);
void creerTas(TasMin *tm);
void supprimerTas(TasMin *tm);

void reorganiserDesc(TasMin *tm, int posParent);
void afficherTas(TasMin *tm);
void afficherSuite(TasMin *tm, int fg, int fd);
