#ifndef PROVA_SIMULADO1_H_
#define PROVA_SIMULADO1_H_
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10


typedef struct Pilha {
    int dados[SIZE];
    int topo;
} Pilha;

typedef struct Aluno {
    int matricula;
    float nota;
} Aluno;

typedef struct ListaEx04 {
    Aluno *aluno;
    struct ListaEx04 *prox;
} ListaEx04;

typedef struct ListaEx05 {
    int info;
    struct ListaEx05 *prox;
} ListaEx05;

int *ex02(int **matriz, int lin, int col);

int ex03(Pilha *pilha);

void ex04(ListaEx04 *lista);

int ex05(ListaEx05 *lista, int elemento);

#endif // PROVA_SIMULADO1_H_
