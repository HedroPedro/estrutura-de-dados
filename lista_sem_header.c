#include "lista_sem_header.h"

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
        free(novoElemento);
        SHOW_ERROR_MSG("TIPO INVALIDO");
        return lista;
    }
    novoElemento->type = type;
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
    printf("NULL\n");
}

ListHeader *removeDataFromList(ListHeader* lista, void *data, uint type){
    ListHeader *anterior = NULL, *atual = lista;
    while(atual != NULL && !isGenericValueEqualToOther(atual->data, data, type)){
        anterior = atual;
        atual = atual->next;
    }

    if(atual == NULL){
        return lista;
    }

    if(anterior == NULL){
        lista = atual->next;
    }else{
        anterior->next = atual->next;
    }

    free(atual->data);
    free(atual);
    return lista;
}

ListHeader *addDataOrdered(ListHeader *lista, void *dataToBeAdd, uint type){
    ListHeader *anterior = NULL, *atual = lista;

    while(atual != NULL && isGenericValueLesserThanOther(atual, dataToBeAdd, type) != -1
          && isGenericValueLesserThanOther(atual, dataToBeAdd, type)){
        anterior = atual;
        atual = atual->next;
    }

    ListHeader *nodeToAdd = (ListHeader *) malloc(sizeof(ListHeader));
    switch(type){
    case INT:
        break;
    case UINT:
        break;
    case CHAR:
        break;
    default:
        free(nodeToAdd);
        SHOW_ERROR_MSG("TIPO INVALIDO");
        return lista;
    }

    nodeToAdd->type = type;

    if(atual == NULL){
        nodeToAdd->next = lista;
        lista = nodeToAdd;
        return lista;
    }

    nodeToAdd->next = anterior->next;
    anterior->next = nodeToAdd;

    return lista;
}

bool isGenericValueEqualToOther(ListHeader *lista, void* actualData, uint type){
    if(lista->type != type){
        return false;
    }

    switch(type){
    case UINT:
        return (*(uint*) lista->data) == (*(uint*) actualData);
    case CHAR:
        return (*(char*) lista->data) == (*(char*) actualData);
    default:
        return (*(int*) lista->data) == (*(int *) actualData);
    }
}

bool isGenericValueLesserThanOther(ListHeader *lista, void *comparedData, uint type){
    if(lista->type != type){
        return ERROR_VALUE;
    }

    switch(type){
    case UINT:
        return (*(uint*) lista->data) < (*(uint*) comparedData);
    case CHAR:
        return (*(char*) lista->data) < (*(char*) comparedData);
    default:
        return (*(int*) lista->data) < (*(int *) comparedData);
    }
}

bool isListEmpt(ListHeader *lista){
    return lista == NULL;
}

bool areTwoListEquals(ListHeader *lista1, ListHeader *lista2){
    ListHeader *p1, *p2;
    for(p1 = lista1, p2 = lista2; p1 != NULL && p2 != NULL; p1 = p1->next, p2 = p2->next){
        if(!isGenericValueEqualToOther(p1->data, p2->data, p1->type)){
            return false;
        }
    }
    return p1 == p2;
}

void freeList(ListHeader *lista){
    ListHeader *next;
    ListHeader *current = lista;
    while(current != NULL){
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}
