#ifndef EX02_H_
#define EX02_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct objeto{
    float peso, area;
} objeto;

float calcPressao(objeto *object);

void ex02(void);

#endif
