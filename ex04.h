#ifndef EX04_H_
#define EX04_H_

#include <stdio.h>
#include <stdlib.h>
#define SIZE 3


typedef struct Aluno {
    float notas[SIZE], media;
} Aluno;

void calcularMedia(Aluno *aluno);

void ex04(void);
#endif
