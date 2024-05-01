#include "lista.h"

int main()
{
    int x = 2;
    ListHeader *listaNova = createList();
    addToList(listaNova, &x, INT);
    printf("%p\n", listaNova);
    showIntegerData((void *) &x);
}
