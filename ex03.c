#include "ex03.h"

int pessoaComMaiorPeso(float *vect, int n, float media){
    int index = 0;
    for(int i = 0; i < n; i++){
        if(fabs((double) vect[i] -  media) > diff){
            index = i;
            diff = fabs(((double) vect[i] -  media));
        }
    }
    return index;
}

void ex03(void){
    int n, i, pos;
    float *vect, media = 0;
    printf("Digite o tamanho do vetor de pesos: ");
    scanf("%d", &n);
    vect = (float *) malloc(n * sizeof(float));
    for(i = 0; i < n; i++){
        printf("Digite o valor: ");
        scanf("%f", &vect[i]);
        media += vect[i];
    }

    media /= n;
    printf("%f\n", media);
    pos = pessoaComMaiorPeso(vect, n, media);
    printf("A pessoa com peso mais longe da media esta na pos %i e %.2f kg", pos, vect[pos]);

    free(vect);
}
