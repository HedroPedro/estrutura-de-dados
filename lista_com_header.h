#ifndef LISTA_H_
#define LISTA_H_
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define GENERIC 1

typedef unsigned short bool;
typedef struct Node Node;
typedef struct ListCabe ListCabe;

#if !GENERIC

struct Node {
    int info;
    struct Node *next;
};

struct ListCabe {
    Node *firstNode;
};

ListCabe *addOrdered(ListCabe *header, int info);
ListCabe *removeDataFromListCabe(ListCabe *header, int infoToBeAdd);
ListCabe *createListHeader(void);
ListCabe *addNode(ListCabe *header, int info);

#else
    typedef void(*printData)(void *);
    typedef bool(*matchData)(void *, void *);
    typedef bool(*compareData)(void *, void *);

    struct Node {
        void *info;
        struct Node *next;
    };

    struct ListCabe {
        compareData compareValues;
        matchData matchValues;
        printData print;
        Node *start;
    };

#endif //NONGENERIC

void printDataInList(ListCabe *header);
void freeListCabeData(ListCabe *header);
bool isListEmpty(ListCabe *header);
bool isTwoListEquals(ListCabe *header1, ListCabe *header2);
#endif //GUARDS
