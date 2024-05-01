#include "lista.h"

ListHeader *createList(void){
    return NULL;
}

ListHeader *addToList(ListHeader *lista, void *data, uint type){
    ListHeader* novoElemento = (ListHeader *) malloc(sizeof(ListHeader));
}

void showIntegerData(void *data){
    printf("%i", *((int *)data));
}

void showUIntegerData(void *data){
    printf("%u", *((uint *)data));
}
void showCharData(void *data){
    printf("%c", *((char *)data));
}

void showDataInList(ListHeader *lista){
    ListHeader *current = lista;
    while(current != NULL){
        current = current->next;
    }
    printf("\n");
}
