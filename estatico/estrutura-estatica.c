#include "estrutura-estatica.h"
#include <stdio.h>
#include <stdlib.h>

Pilha *create_pilha(void){
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    if(!pilha){
        PRINT_ERROR("IMPOSSIVEL ALOCAR PILHA");
        exit(1);
    }
}

int pop_pilha(Pilha *pilha){
    if(pilha->topo == 0){
        PRINT_ERROR("PILHA VAZIA");
        exit(1);
    }
    pilha->topo--;
    return pilha->vector[pilha->topo];
}

int get_pilha_size(Pilha *pilha){
    return pilha->topo;
}

void push_in_pilha(Pilha *pilha, int val){
    if(pilha->topo == MAX_ELEMENTO){
        PRINT_ERROR("PILHA CHEIA");
        return;
    }
    pilha->vector[pilha->topo] = val;
    pilha->topo++;
}

Fila *g(void){
    Fila fila = (Fila *) malloc(sizeof(Fila));
    if(!fila){
        PRINT_ERROR("SEM ESPACO PARA CRIAR UMA FILA");
        exit(1);
    }
    fila->top = fila->start = 0;
    return fila;
}

int get_first_in_fila(Fila *fila){
    int value;
    if(fila->start == fila->top){
        PRINT_ERROR("Fila vazia");
        exit(1);
    }
    value = fila->vector[fila->start];
    fila->start++;
    if(fila->start == MAX_ELEMENTO){
        f->start == 0;
    }
    return value;
}

int get_fila_size(Fila *fila){
    int tam = fila->top - fila->start;
    if(tam < 1){
        tam += MAX_ELEMENTO;
    }
    return tam;
}

void push_in_fila(Fila *fila, int val){
    if((fila->top + 1 == fila->start) || (fila->start == 0 && fila->top == MAX_ELEMENTO-1)){
        PRINT_ERROR("FILA CHEIA");
        exit(1);
    }

    fila->vector[fila->top] = val;
    fila->top++;
    if(fila->top == MAX_ELEMENTO){
        fila->top = 0;
    }
}

Lista *create_lista(void){
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    if(!lista){
        PRINT_ERROR("SEM ESPACO PARA ALOCAR");
        exit(1);
    }
    lista->last = 0;
    return lista;
}

int get_value_in_pos(Lista *lista, int pos){
    if(pos >= lista->last){
        PRINT_ERROR("POSICAO INVALIDA");
        exit(1);
    }
    return lista->vector[pos];
}

int get_lista_size(Lista *lista){
    return lista->last;
}

int remover_in_lista(Lista *lista, int pos){
    int val;
    if(pos >= lista->last){
        PRINT_ERROR("POSICAO INVALIDA");
        exit(1);
    }

    if(!lista->last){
        PRINT_ERROR("LISTA VAZIA");
        exit(1);
    }

    val = lista[pos];
    for(int i = pos; i < lista->last; i++){
        lista->vector[i] = lista->vector[i+1];
    }
    lista->last--;
    return val;
}

int remover_final_in_lista(Lista *lista){
    if(lista->last == 0){
        PRINT_ERROR("LISTA VAZIA");
        exit(1);
    }
}

void push_last_in_lista(Lista *lista, int val){
    if(lista->last == MAX_ELEMENTO-1){
        PRINT_ERROR("LISTA CHEIA");
        exit(1);
    }
    lista->vector[lista->last] = val;
    lista->last++;
}

void push_in_lista_pos(Lista *lista, int val, int pos){
    if(lista->last == MAX_ELEMENTO-1){
        PRINT_ERROR("LISTA CHEIA");
        exit(1);
    }

    for(int i = lista->last; i > pos; i--){
        lista->vector[i] = lista->vector[i-1];
    }
    lista->last++;
    lista->vector[pos] = val;
}
