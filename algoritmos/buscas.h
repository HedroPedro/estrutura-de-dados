#ifndef BUSCAS_H_
#define BUSCAS_H_

typedef int(*Search_alg)(int *, int, int, int *);

int busca_linear(int *vet, int tam, int elem, int *qtd_int);
int busca_linear_ord(int *vet, int tam, int elem, int *qtd_int);
int busca_binaria(int *vet, int tam, int elem, int *qtd_int);

#endif // BUSCAS_H_
