#ifndef LISTA_H_
#define LISTA_H_

#include <stdio.h>
#include <stdlib.h>

#define SHOW_ERROR_MSG(reason) fprintf(stderr, "Erro na linha %i!RAZAO: %s\n", __LINE__, #reason)
#define ERROR_VALUE -1
#define true 1
#define false 0

typedef unsigned int uint;
typedef unsigned short bool;
typedef void(*DisplayData)(void *);

typedef enum {
    INT = 0, UINT, CHAR,
} Types;

typedef struct ListHeader {
    void *data;
    Types type;
    DisplayData showData;
    struct ListHeader *next;
} ListHeader;

ListHeader *createList(void);
void freeList(ListHeader *lista);
ListHeader *addToList(ListHeader *lista, void *data, uint type);
void removeDataFromList(void *data, uint type);
void showDataInList(ListHeader *lista);
void showIntegerData(void *data);
void showUIntegerData(void *data);
void showCharData(void *data);


#endif
