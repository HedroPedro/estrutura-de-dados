#ifndef EX01_H_
#define EX01_H_
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

typedef struct circulo {
    float raio;
} circulo;

float calcularArea(circulo *circ);

float calcularPerimeto(circulo *circ);

void ex01(void);

#endif
