#include "lista_com_header.h"

int main(){
    #if !GENERIC
        ListCabe *listaCabe1 = createListHeader();
        addNode(listaCabe1, 2);
        addNode(listaCabe1, 3);
        printDataInList(listaCabe1);
        addOrdered(listaCabe1, 1);
        printDataInList(listaCabe1);
        listaCabe1 = removeDataFromListCabe(listaCabe1, 2);
        printDataInList(listaCabe1);

    #else
        ListCabe *ListCabe1 = createListHeader(sizeof(int), INT, )
    #endif
}
