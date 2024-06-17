#include "ordenacao.h"

void swap(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}

void selection_sort(int *vet, int tam){
    int i, j, min_index;

    for(i = 0; i < tam-1; i++){
        min_index = i;
        for(j = i+1; j < tam; j++){
            if(vet[j] < vet[min_index]){
                min_index = j;
            }

            if(min_index != i){
                swap(&vet[min_index], &vet[i]);
            }
        }
    }
}

void insertion_sort(int *vet, int tam){
    int i, chave, j;
    for(i = i; i < tam; i++){
        chave = vet[i];
        j = i - 1;

        while(j >-1 && vet[j] > chave){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j + 1] = chave;
    }
}

void bubble_sort(int *vet, int tam){
    int j;
    for(int i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            if(vet[i] > vet[j]){
                swap(&vet[i], &vet[j]);
            }
        }
    }
}
