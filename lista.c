#include "lista.h"

Lista *add_in_lista(Lista *lst, int info){
    Lista *elemento = (Lista *) malloc(sizeof(Lista));
    elemento->info = info;
    elemento->prox = lst;
    return elemento;
}

void inverter_lista(Lista *lst){
    Lista *cur = lst, *next, *ant = NULL;
    while(cur != NULL){
        next = cur->prox;
        cur->prox = ant;
        ant = cur;
        cur = next;
    }
}
