#ifndef LISTA_H_
#define LISTA_H_
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef unsigned short bool;

typedef struct Node {
    int info;
    struct Node *next;
} Node;

typedef struct ListCabe {
    Node *firstNode;
} ListCabe;

ListCabe *createListHeader(void);
ListCabe *addNode(ListCabe *header, int info);
ListCabe *addOrdered(ListCabe *header, int info);
ListCabe *removeDataFromListCabe(ListCabe *header, int infoToBeAdd);
ListCabe *freeListCade(ListCabe *header);
void printDataInList(ListCabe *header);
ListCabe *freeListCabeData(ListCabe *header);
bool isListEmpty(ListCabe *header);
bool isTwoListEquals(ListCabe *header1, ListCabe *header2);

#endif
