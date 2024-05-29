#ifndef LISTA_H_
#define LISTA_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    int info;
    struct Lista *prox;
} Lista;


Lista *add_in_lista(Lista *lst, int info);
Lista *free_lista(Lista *lst);

/** Prova **/
void inverter_lista(Lista *lst);

#endif // LISTA_H_
