#include "lista.h"

int main()
{
    int x = 2;
    ListHeader *listaNova = createList();
    listaNova = addToList(listaNova, (void*) &x, INT);
    x = -12;
    listaNova = addToList(listaNova, (void*) &x, INT);
    printf("%p\n", listaNova);
    showDataInList(listaNova);
    freeList(listaNova);
}
