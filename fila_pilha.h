#ifndef FILA_PILHA_H_
#define FILA_PILHA_H_
#include <stdio.h>
#include <stdlib.h>

#define ERROR_VALUE -1
#define false 0
#define true 1
typedef unsigned short bool;
typedef struct Elemento Elemento;
typedef struct Stack Stack;
typedef struct Queue Queue;

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

    /**Prova-Exercicio**/
    typedef struct Aluno {
        int id;
        float nota;
        struct Aluno *next;
    } Aluno;
    typedef struct AlunoStack {
        Aluno aluno;
    } AlunoStack;
    void showMenu1(Stack *p1);
    void showMenu2(Stack *p1);

    /** PILHAS **/
    Stack *createStack(void);
    Stack *copyStack(Stack *pilha);
    void pushInStack(Stack *pilha);
    void pushInStackValue(Stack *pilha, int val);
    void addFibboValuesInStack(Stack *pilha, int qtd);
    void showStackInfo(Stack *pilha);
    int countOddsOnStack(Stack *pilha);
    int countEvensOnStack(Stack *pilha);
    int popStack(Stack *pilha);
    bool areTwoStackEquals(Stack *p1, Stack *p2);

    /** FILAS **/
    Queue *createQueue(void);
    Queue *copyQueue(Queue *fila);
    void showQueueInfo(Queue *fila);
    void addInQueue(Queue *fila);
    void addInQueueVal(Queue *fila, int val);
    int popQueue(Queue *fila);
    int countOddsOnQueue(Queue *fila);
    int countEvensOnQueue(Queue *fila);
    bool areTwoQueueEquals(Queue *fila);

    /** GERAL/Exercicio **/
    void compareStackAndQueue(Stack *pilha, Queue *fila);
    void popNumberInStack(Stack *p1, int num);

/** Funções que podem ser implementadas sem alterar as funções **/
/** Pilha **/
void printDataInStack(Stack *pilha);
void freeDataInStack(Stack *pilha);
/** Fila **/
void printDataInQueue(Queue *fila);
void freeDataInQueue(Queue *fila);

#endif
