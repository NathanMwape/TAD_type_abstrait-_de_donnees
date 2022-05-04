#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct dlistNode{
    int val;
    struct dlistNode *next;
    struct dlistNode *prec;
}dlistNode;

typedef struct dlist{
    int taille;
    struct dlistNode *premier;
    struct dlistNode *dernier;
}dlist;
