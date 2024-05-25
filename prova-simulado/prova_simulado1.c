#include "prova_simulado1.h"

//////////////////////////////////////////
////              INFO               /////
//////////////////////////////////////////

/**
 Todas as structs e cabeçalhos das funções estão armazenadas em prova_simulado.h
**/

/* Converter um matriz em vetor, utilizando malloc e um iterador
*  AVISO: provavelmente tera que ser feito um casting para (int **)
*  int **matriz - matriz que deseja converter
*  int lin - quantidade de linhas
*  int col - quantidade de colunas
*  Retornamos o vetor com os dados da matriz
**/
int *ex02(int **matriz, int lin, int col){
    int *vetor = (int *) malloc(lin * col * sizeof(int));
    int iterador = 0;
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            vetor[iterador] = matriz[i][j];
        }
    }
    return vetor;
}

/* Pega o valor que está armazenado no topo da função
*  AVISO: Se o topo for igual a 0, o programa é fechado, pois não existe mais elmenetos a serem retirados
*  Pilha *pilha - O ponteiro da pilha que desejamos retirar o topo
*  Retornamos, num sucesso, o número no topo
*/
int ex03(Pilha *pilha){
    if(pilha->top == 0){
        printf("Pilha vazia");
        exit(1); // Poderia ser um return, mas foi indicado utilizar o exit que encerra o programa
    }
    pilha->topo--;
    return pilha->dados[pilha->topo];
}

/* Limpa uma lista alocada dinamicamente, também limpa o campo aluno
*  ListaEx04 *lista - lista que desejamos apagar
*/
void ex04(ListaEx04 *lista){
    ListaEx04 *atual = lista;
    ListaEx04 *prox = NULL;
    while(atual != NULL){
        free(atual->aluno); //Lembre-se, estamos trabalhando com um ponteiro, a struct Aluno está sendo alocada dinamicamente
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

/* Função para contar quantas vezes um determinado numero apareceu na lista
*  ListaEx05 *lista - lista que queremos checar
*  int elemento - elemento que queremos verificar quantas vezes apareceu na lista
*  Retornamos a quantidade de vezes que um elemento apareceu na lista
*/
int ex05(ListaEx05 *lista, int elemento){
    int contador = 0;
    for(ListaEx05 *atual; atual != NULL; atual = atual->prox){
        if(atual->info == elemento){
            contador++;
        }
    }
    return contador;
}
