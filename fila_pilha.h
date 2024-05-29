#ifndef FILA_PILHA_H_
#define FILA_PILHA_H_
#include <stdio.h>
#include <stdlib.h>

#define ERROR_VALUE -1
#define false 0
#define true 1
typedef unsigned char bool;
typedef struct Elemento Elemento;
typedef struct Stack Stack;
typedef struct FilaEx4 FilaEx4;
typedef struct Queue Queue;
typedef struct Aluno Aluno;


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

    struct FilaEx4 {
        Aluno *start, *end;
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
    bool is_pilha_vazia(Stack *p);

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

/**Prova**/
int is_fila_ordered(Queue *fila);
void remover_elemento_pilha(Stack *pilha, int elemento);
float get_percentage(FilaEx4 *fila, float nota);

#endif
