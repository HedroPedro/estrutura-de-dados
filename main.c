#include "fila_pilha.h"

int main(){
    int val;
    Stack *stack = createStack();
    Queue *queue = createQueue();
    pushInStack(stack);
    pushInStack(stack);
    printDataInStack(stack);
    val = popStack(stack);
    printf("%d!\n", val);
    freeDataInStack(stack);
    printDataInQueue(queue);
    addInQueue(queue);
    addInQueue(queue);
    printDataInQueue(queue);
    val = popQueue(queue);
    printf("%d!\n", val);
    addInQueue(queue);
    printDataInQueue(queue);
    freeDataInQueue(queue);
    printDataInQueue(queue);
    free(stack);
    free(queue);
}
