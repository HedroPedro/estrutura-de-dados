#ifndef ESTRUTURA_ESTATICA_H_
#define ESTRUTURA_ESTATICA_H_
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTO 10
#define ERROR_VALUE -1
#define PRINT_ERROR(REASON) fprintf(stderr, "Erro na linha %i, razao: %s", __LINE__, REASON)


typedef struct Pilha{
    int vector[MAX_ELEMENTO];
    int topo;
} Pilha;

typedef struct Fila {
    int vector[MAX_ELEMENTO];
    int top, start;
} Fila;

typedef struct Lista {
    int vector[MAX_ELEMENTO];
    int last;
} Lista;

Pilha *create_pilha(void);
int pop_pilha(Pilha *pilha);
int get_pilha_size(Pilha *pilha);
void push_in_pilha(Pilha *pilha, int val);

Fila *create_fila(void);
int get_first_in_fila(Fila *fila);
int get_fila_size(Fila *fila);
void push_in_fila(Fila *fila, int val);

Lista *create_lista(void);
int get_value_in_pos(Lista *lista, int pos);
int get_lista_size(Lista *lista);
int remover_in_lista(Lista *lista, int pos);
int remover_final_in_lista(Lista *lista);
void push_last_in_lista(Lista *lista, int val);
void push_in_lista_pos(Lista *lista, int val, int pos);

#endif // ESTRUTURA-ESTATICA_H_
