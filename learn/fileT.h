#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct elementF{
    int value;
    elementF *next;
}elementF;

typedef struct File{
    elementF *premier;

}File;
void enfiler(File *file, int val);
