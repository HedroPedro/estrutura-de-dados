#include "lista_com_header.h"

ListCabe *createListHeader(void){
    ListCabe *header = (ListCabe *) malloc(sizeof(ListCabe));
    header->firstNode = NULL;
    return header;
}

ListCabe *addNode(ListCabe *header, int info){
    Node *current;
    if(!header->firstNode){
        header->firstNode = (Node *) malloc(sizeof(Node));
        header->firstNode->info = info;
        header->firstNode->next = NULL;
        return header;
    }

    for(current = header->firstNode; current->next != NULL; current = current->next);
    current->next = (Node *) malloc(sizeof(Node));
    current->next->info = info;
    current->next->next = NULL;
    return header;
}

ListCabe *addOrdered(ListCabe *header, int info){
    Node *current, *anterior = NULL;

    if(!header->firstNode){
        header->firstNode = (Node *) malloc(sizeof(Node));
        header->firstNode->info = info;
        header->firstNode->next = NULL;
        return header;
    }

    current = header->firstNode;
    while(current != NULL && current->info < info){
        anterior = current;
        current = current->next;
    }

    Node *novo = (Node *) malloc(sizeof(Node));
    novo->info = info;
    if(!anterior){
        header->firstNode = novo;
        novo->next = current;
    }else{
        anterior->next = novo;
        novo->next = current;
    }

    return header;
}

ListCabe *removeDataFromListCabe(ListCabe *header, int infoToBeRemoved){
    Node *current, *anterior = NULL;
    if(!header->firstNode){
        return header;
    }

    current = header->firstNode;
    while(current != NULL && current->info != infoToBeRemoved){
        anterior = current;
        current = current->next;
    }

    if(!anterior){
        free(header->firstNode);
        header->firstNode = current->next;

    }else {
        anterior->next = current->next;
        free(current);
    }

    return header;
}

ListCabe *freeListCade(ListCabe *header){
    if(!header->firstNode){
        fprintf(stderr, "CAEBCALHO NAO ESTA LIMPO");
        return header;
    }

    free(header);
    return NULL;
}

void printDataInList(ListCabe *header){
    Node *current;

    if(!header->firstNode){
        return;
    }

    printf("Cabecalho->");
    for(current = header->firstNode; current != NULL; current = current->next){
        printf("%d->", current->info);
    }
    printf("NULL\n");
}

ListCabe *freeListCabeData(ListCabe *header){
    Node *current, *tmp;
    if(!header->firstNode){
        return header;
    }

    current = header->firstNode;
    while(current){
        tmp = current->next;
        free(current);
        current = tmp;
    }
    header->firstNode = NULL;
    header = freeListCade(header);
    return header;
}
bool isListEmpty(ListCabe *header){
    return !header->firstNode;
}

bool isTwoListEquals(ListCabe *header1, ListCabe *header2){
    Node *p1, *p2;

    for(p1 = header1->firstNode, p2 = header2->firstNode;
            p1 != NULL && p2 != NULL;
            p1=p1->next, p2=p2->next){
        if(p1->info != p2->info){
            return false;
            }
        }

    return p1 == p2;
}
