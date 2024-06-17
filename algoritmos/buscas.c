#include "buscas.h"
#include <stdio.h>

int busca_linear(int *vet, int tam, int elem, int *qtd_int){
    for(int i = 0; i < tam; i++){
        (*qtd_int)++;
        if(vet[i] == elem){
            return i;
        }
    }
    return -1;
}

int busca_linear_ord(int *vet, int tam, int elem, int *qtd_int){
    for(int i = 0; i < tam; i++){
        (*qtd_int)++;
        if(vet[i] == elem){
            return i;
        }

        if(vet[i] > elem){
            return -1;
        }
    }
    return -1;
}


int busca_binaria(int *vet, int tam, int elem, int *qtd_int){
    int inicio = 0;
    int fim = tam-1;
    int meio = 0;
    while(inicio <= fim){
        *qtd_int += 1;
        meio = (inicio+fim)/2;
        if(elem < vet[meio]){
            fim = meio-1;
        }else{
            if(elem > vet[meio]){
                inicio = meio+1;
            }else{
                return meio;
            }
        }
    }

    return -1;
}
