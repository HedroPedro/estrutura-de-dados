#ifndef FILA_PILHA_H_
#define FILA_PILHA_H_
#include <stdio.h>
#include <stdlib.h>

#define NONGENERIC 1
#define ERROR_VALUE -1
typedef struct Elemento Elemento;
typedef struct Stack Stack;
typedef struct Queue Queue;

#if NONGENERIC
    struct Elemento {
        int info;
        struct Elemento *next;
    };

    struct Stack {
        Elemento *top;
    };

    struct Queue {
        Elemento *first, *last;
    };

    /** PILHAS **/
    Stack *createStack(void);
    void pushInStack(Stack *pilha);
    int popStack(Stack *pilha);

    /** FILAS **/
    Queue *createQueue(void);
    void addInQueue(Queue *fila);
    int popQueue(Queue *fila);

#else

#endif // NONGENERIC

/** Funções que podem ser implementadas sem alterar as funções **/
/** Pilha **/
void printDataInStack(Stack *pilha);
void freeDataInStack(Stack *pilha);
/** Fila **/
void printDataInQueue(Queue *fila);
void freeDataInQueue(Queue *fila);

#endif
