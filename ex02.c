#include "ex02.h"

float calcPressao(objeto *object){
    return object->peso/object->area;
}

void ex02(void){
    int n, i;
    objeto *objetos;
    printf("Digite o tamanho do vetor: ");
    scanf("%i", &n);
    objetos = (objeto *)calloc(n, sizeof(objeto));
    for(i = 0; i < n; i++){
        printf("Digite o peso e area: ");
        scanf("%f%f", &objetos[i].area, &objetos[i].peso);
    }

    for(i = 0; i < n; i++){
        printf("A pressao e: %.2f\n", calcPressao(&objetos[i]));
    }
}
