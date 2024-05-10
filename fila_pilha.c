#include "fila_pilha.h"
#define NONGENERIC 1

#if NONGENERIC
    Stack *createStack(void){
        Stack *pilha = (Stack *) malloc(sizeof(Stack));
        if(pilha){
            pilha->top = NULL;
        }
        return pilha;
    }

    void pushInStack(Stack *pilha){
        Elemento *elem = (Elemento *) malloc(sizeof(Elemento));
        printf("Digite o valor: ");
        scanf("%i", &elem->info);
        elem->next = pilha->top;
        pilha->top = elem;
    }

    int popStack(Stack *pilha){
        Elemento *aux;
        int value;
        if(!pilha->top){
            return ERROR_VALUE;
        }
        aux = pilha->top;
        value = aux->info;
        pilha->top = aux->next;
        free(aux);
        return value;
    }

    void printDataInStack(Stack *pilha){
        Elemento *aux;
        for(aux = pilha->top; aux; aux = aux->next){
            printf("%d\n|\nv\n", aux->info);
        }
        printf("NULL\n");
    }

    void freeDataInStack(Stack *pilha){
        Elemento *aux, *tmp;
        for(aux = pilha->top; aux; aux = tmp){
            tmp = aux->next;
            free(aux);
            pilha->top = tmp;
        }
    }

    Queue *createQueue(void){
        Queue *fila = (Queue *) malloc(sizeof(Queue));
        if(fila){
            fila->last = fila->first = NULL;
        }
        return fila;
    }

    void addInQueue(Queue *fila){
        Elemento *elemToAdd = (Elemento *) malloc(sizeof(Elemento));
        printf("Digite o dado para adicionar: ");
        scanf("%d", &elemToAdd->info);
        if(!fila->first){
            fila->last = fila->first = elemToAdd;
            return;
        }
        fila->last->next = elemToAdd;
        fila->last = elemToAdd;
        fila->last->next = NULL;
    }

    int popQueue(Queue *pilha){
        int aux;
        Elemento *first = pilha->first;
        if(!first){
            return ERROR_VALUE;
        }
        aux = first->info;
        pilha->first = first->next;
        free(first);
        return aux;
    }

    void printDataInQueue(Queue *fila){
        Elemento *elem;
        for(elem = fila->first; elem; elem = elem->next){
            printf("%d->", elem->info);
        }
        printf("NULL\n");
    }

    void freeDataInQueue(Queue *fila){
        Elemento *aux = fila->first;
        while(aux){
            fila->first = aux->next;
            free(aux);
            aux = fila->first;
        }
    }
#else

#endif // NONGENERIC
