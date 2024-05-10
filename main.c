#include "fila_pilha.h"

int main(){
<<<<<<< HEAD
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
=======
    #if !GENERIC
        ListCabe *listaCabe1 = createListHeader();
        addNode(listaCabe1, 2);
        addNode(listaCabe1, 3);
        printDataInList(listaCabe1);
        addOrdered(listaCabe1, 1);
        printDataInList(listaCabe1);
        listaCabe1 = removeDataFromListCabe(listaCabe1, 2);
        printDataInList(listaCabe1);

    #else
        ListCabe *ListCabe1 = createListHeader(sizeof(int), INT, )
    #endif
>>>>>>> f2a9385e9d7a71331467f199fdd71e76cf14328c
}
