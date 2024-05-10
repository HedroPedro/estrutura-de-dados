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

    //Funções que apenas servem para lista de tipo fixo
    ListCabe *addOrdered(ListCabe *header, int info);
    ListCabe *removeDataFromListCabe(ListCabe *header, int infoToBeAdd);
    ListCabe *createListHeader(int size, int type, compareData comparatorFunc, printData printFunc, addNode addFunc);
    ListCabe *addNode(ListCabe *header, int info);

#else
    #ifndef __STDC_VERSION__
        #define INT 0
        #define UINT 1
        #define CHAR 2
    #else
        typedef enum {
            INT,
            UINT,
            CHAR,
        } Types;
    #endif // __STDC_VERSION__
    typedef void(*printData)(void *);
    typedef void(*addNode)(void *);
    typedef bool(*matchData)(void *, void *);
    typedef bool(*compareData)(void *, void *);

    struct Node {
        void *info;
        struct Node *next;
    };

    struct ListCabe {
        compareData compareValues;
        printData print;
        addNode addNode;
        Node *start;
    };

    ListCabe *createListHeader(int size, int type, compareData comparatorFunc, printData printFunc, addNode addFunc);

#endif //NONGENERIC

/*
    Essas funções são capazes de executar as mesmas funções, sendo genericas ou não. Apenas depende do macro
*/
void printDataInList(ListCabe *header);
void freeListCabeData(ListCabe *header);
bool isListEmpty(ListCabe *header);
bool isTwoListEquals(ListCabe *header1, ListCabe *header2);
#endif //GUARDS
