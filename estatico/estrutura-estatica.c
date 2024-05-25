#include "estrutura-estatica.h"

Pilha *create_pilha(void){
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    if(!pilha){
        PRINT_ERROR("IMPOSSIVEL ALOCAR PILHA");
        return NULL;
    }
    pilha->top = 0;
    return pilha;
}

int pop_pilha(Pilha *pilha){
    if((--pilha->top) < 0){
        pilha->top = 0;
        PRINT_ERROR("pilha vazia");
        return ERROR_VALUE;
    }
    return pilha->vector[pilha->top];
}

int get_pilha_size(Pilha *pilha){
    return pilha->top;
}

void push_in_pilha(Pilha *pilha, int val){
    if((pilha->top+1) > MAX_ELEMENTO-1){
        PRINT_ERROR("TAMANHO MAXIMO JA ALOCADO");
        return;
    }

    pilha->vector[pilha->top] = val;
    pilha->top++;
}

Fila *create_fila(void){
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    if(!fila){
        PRINT_ERROR("SEM ESPACO PARA ALLOCAR FILA");
        return NULL;
    }
    fila->start = fila->top = 0;
    return fila;
}

int get_first_in_fila(Fila *fila){
    int ret_val;
    if(fila->top == fila->start){
        PRINT_ERROR("FILA VAZIA");
        return ERROR_VALUE;
    }
    ret_val = fila->vector[fila->start];
    fila->start++;
    if(fila->start == MAX_ELEMENTO){
        fila->start = 0;
    }
    return ret_val;
}

int get_fila_size(Fila *fila){
    int tam = fila->top - fila->start;
    if(tam < 1){
        tam += MAX_ELEMENTO;
    }
    return tam;
}

void push_in_fila(Fila *fila, int val){
    if(fila->top+1 == fila->start || (
        fila->top == MAX_ELEMENTO-1 && !fila->start)){
            PRINT_ERROR("FILA CHEIA");
            return;
        }

    fila->vector[fila->top] = val;
    fila->top++;
    if(fila->top == MAX_ELEMENTO){
        fila->top = 0;
    }
}

Lista *create_lista(void){
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if(!lista){
        PRINT_ERROR("SEM ESPACO PARA ALOCAR UMA LISTA");
        return NULL;
    }
    lista->last = 0;
    return lista;
}

int get_value_in_pos(Lista *lista, int pos){
    if(pos < 0 || pos > lista->last){
        PRINT_ERROR("POSICAO INVALIDA");
        return ERROR_VALUE;
    }
    return lista->vector[pos];
}

int get_lista_size(Lista *lista){
    return lista->last;
}

void push_in_lista_pos(Lista *lista, int val, int pos){
    if(pos < 0 || pos > MAX_ELEMENTO-1){
        PRINT_ERROR("POSICAO INVALIDA");
        return;
    }

    if(lista->last == MAX_ELEMENTO){
        PRINT_ERROR("LISTA CHEIA");
        return;
    }

    for(int i = lista->last; i > pos; i--){
        lista->vector[i] = lista->vector[i-1];
    }
    lista->vector[pos] = val;
    lista->last++;
}

void push_last_in_lista(Lista *lista, int val){
    if(lista->last == MAX_ELEMENTO){
        PRINT_ERROR("LISTA CHEIA");
    }
    lista->vector[lista->last];
    lista->last++;
}
