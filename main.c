#include "lista.h"

int main()
{
    int x = 2;
    ListHeader *listaNova = createList();
    listaNova = addToList(listaNova, &x, INT);
    x = -12;
    listaNova = addToList(listaNova, &x, INT);
    printf("%p\n", listaNova);
    showDataInList(listaNova);
    listaNova = removeDataFromList(listaNova, &x, INT);
    showDataInList(listaNova);
    x = 2;
    listaNova = removeDataFromList(listaNova, &x, INT);
    showDataInList(listaNova);
    x = 1;
    listaNova = addDataOrdered(listaNova, &x, INT);
    showDataInList(listaNova);
    freeList(listaNova);
}
