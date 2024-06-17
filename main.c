#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmos/buscas.h"

int geraPos(int tam){
    return rand() % tam;
}

void save_worst(FILE *output, Search_alg search_alg, int size){
    int *vetor, qtd = 0, i;
    vetor = (int *) malloc(sizeof(int) * size);
    for(i = 0; i < size; i++){
        vetor[i] = i;
    }
    for(i = 0; i < 30; i++){
        search_alg(vetor, size, size+1, &qtd);
        fprintf(output,"%i ", qtd);
        qtd = 0;
    }
    fprintf(output, "\n");
    free(vetor);
}

void save_medium(FILE *output, Search_alg search_alg, int size){
    int *vetor, qtd = 0, i, total = 30;
    vetor = (int *) malloc(sizeof(int) * size);
    for(i = 0; i < size; i++){
        vetor[i] = i;
    }

    if(search_alg == busca_binaria){
        total = 120;
    }

    for(i = 0; i < total; i++){
        search_alg(vetor, size, vetor[geraPos(size)], &qtd);
        fprintf(output,"%i ", qtd);
        qtd = 0;
    }

    fprintf(output, "\n");
    free(vetor);
}

int main(){
    int qtd_interacoes = 0, j;
    int *vet, vetor[] = {1, 2, 3, 4, 5};
    FILE *arq_pior = fopen("iteracoesPiorCaso.txt", "w");
    FILE *arq_medio = fopen("iteracoesCasoMedio.txt", "w");
    for(int i = 5000; i < 50001; i += 5000){
        save_worst(arq_pior, busca_linear, i);
        save_medium(arq_medio, busca_linear, i);
    }
    for(int i = 5000; i < 50001; i += 5000){
        save_worst(arq_pior, busca_linear_ord, i);
        save_medium(arq_medio, busca_linear_ord, i);
    }

    for(int i = 5000; i < 50001; i += 5000){
        save_worst(arq_pior, busca_binaria, i);
        save_medium(arq_medio, busca_binaria, i);
    }
    fclose(arq_pior);
    fclose(arq_medio);
}
