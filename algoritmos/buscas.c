#include "buscas.h"

int busca_linear(int *vet, int tam, int elem){
    for(int i = 0; i < tam; i++){
        if(vet[i] == elem){
            return i;
        }
    }
    return -1;
}

int busca_linear_ord(int *vet, int tam, int elem){
    for(int i = 0; i < tam; i++){
        if(vet[i] == elem){
            return i;
        }

        if(vet[i] > elem){
            return -1;
        }
    }
    return -1;
}


int busca_binaria(int *vet, int tam, int elem){
    int inicio = 0;
    int fim = tam;
    int meio;
    while(inicio <= fim){
        meio = (inicio+meio)>>1;
        if(vet[meio] == elem){
            return meio;
        }

        if(vet[meio] < elem){
            fim = meio-1;
            continue;
        }

        inicio = meio+1;
    }

    return -1;
}
