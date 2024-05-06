#include "ex01.h"

float calcularArea(circulo *circ){
    return PI * circ->raio;
}

float calcularPerimeto(circulo *circ){
    return PI * circ->raio * 2;
}

void ex01(void){
    int size, i;
    circulo *vector;
    printf("Digite o tamanho do vetor: ");
    scanf("%i", &size);
    vector = (circulo *) malloc(sizeof(circulo) * size);
    for(i = 0; i < size; i++){
        printf("Digite o raio: ");
        scanf("%f", &vector[i].raio);
    }

    for(i = 0; i < size; i++){
        printf("Perimetro %.2f e Area %.2f do circulo %i\n", calcularPerimeto(&vector[i]), calcularArea(&vector[i]), i+1);
    }
}
