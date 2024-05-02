#include "lista.h"

ListHeader *createList(void){
    return NULL;
}

ListHeader *addToList(ListHeader *lista, void *data, uint type){
    ListHeader* novoElemento = (ListHeader *) malloc(sizeof(ListHeader));
    novoElemento->next = lista;
    switch(type){
    case INT:
        novoElemento->data = malloc(sizeof(int));
        *(int*)novoElemento->data = *(int *)data;
        novoElemento->showData = showIntegerData;
        break;
    case UINT:
        novoElemento->data = malloc(sizeof(uint));
        *(uint*)novoElemento->data = *(uint *)data;
        novoElemento->showData = showUIntegerData;
        break;
    case CHAR:
        novoElemento->data = malloc(sizeof(char));
        *(char*)novoElemento->data = *(char *)data;
        novoElemento->showData = showCharData;
        break;
    default:
        novoElemento->data = malloc(sizeof(int));
        *(int *)novoElemento->data = ERROR_VALUE;
        novoElemento->showData = showIntegerData;
        SHOW_ERROR_MSG(TIPO INVALIDO);
    }
    return novoElemento;
}

void showIntegerData(void *data){
    printf("%i->", *((int *)data));
}

void showUIntegerData(void *data){
    printf("%u->", *((uint *)data));
}
void showCharData(void *data){
    printf("%c->", *((char *)data));
}

void showDataInList(ListHeader *lista){
    ListHeader *current = lista;
    while(current != NULL){
        current->showData(current->data);
        current = current->next;
    }
    printf("NULL");
}

void removeDataFromList(void *data, uint type){

}

void freeList(ListHeader *lista){
    for(ListHeader *current = lista; current != NULL; current = lista){
        free(current->data);
        lista = lista->next;
        free(current);
    }
}
