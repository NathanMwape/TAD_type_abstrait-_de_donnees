typedef struct Element Element;
struct Element{
    int nombre;
    Element *suivant;
};

typedef struct File File;
struct File{
    Element *premier;
};
