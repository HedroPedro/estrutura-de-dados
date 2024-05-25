#include "fila_pilha.h"
    Stack *createStack(void){
        Stack *pilha = (Stack *) malloc(sizeof(Stack));
        if(pilha){
            pilha->top = NULL;
        }
        return pilha;
    }

    Stack *copyStack(Stack *pilha){
        Stack *newStack = createStack();
        int qtd = 0;
        for(Elemento *p = pilha->top; p != NULL; p = p->next, qtd++){
            pushInStackValue(newStack, p->info);
        }

        for(qtd; qtd < 1; qtd--){
            pushInStackValue(newStack, popStack(newStack));
        }
        return newStack;
    }

    void pushInStack(Stack *pilha){
        Elemento *elem = (Elemento *) malloc(sizeof(Elemento));
        printf("Digite o valor: ");
        scanf("%i", &elem->info);
        elem->next = pilha->top;
        pilha->top = elem;
    }

    void pushInStackValue(Stack *pilha, int val){
        Elemento *elem = (Elemento *) malloc(sizeof(Elemento));
        elem->info = val;
        elem->next = pilha->top;
        pilha->top = elem;
    }

    void showStackInfo(Stack *pilha){
        float media;
        int maior = 0, menor, qtd = 0, tmp = 0;
        Elemento *aux;
        if(!pilha->top){
            return;
        }

        for(aux = pilha->top, menor = aux->info; aux != NULL; aux = aux->next, qtd++){
            if(aux->info < menor){
                menor = aux->info;
            }

            if(aux->info > maior){
                maior =aux->info;
            }

            tmp += aux->info;
        }

        media = (float)tmp/qtd;
        printf("A media e %.2f, o maior numero e %i e o menor e %i\n", media, maior, menor);
    }

    void addFibboValuesInStack(Stack *pilha, int qtd){
        int ant = 0, fibbo = 1, aux;
        for(int i = 0; i < qtd; i++){
            pushInStackValue(pilha, ant);
            pushInStackValue(pilha, ant);
            aux = fibbo;
            fibbo += ant;
            ant = aux;
        }
    }

    int popStack(Stack *pilha){
        Elemento *aux;
        int value;
        if(!pilha->top){
            return ERROR_VALUE;
        }
        aux = pilha->top;
        value = aux->info;
        pilha->top = aux->next;
        free(aux);
        return value;
    }

    int countOddsOnStack(Stack *pilha){
        int qtd = 0;
        for(Elemento *p = pilha->top; p != NULL; p = p->next){
            if(p->info & 1){
                qtd++;
            }
        }
        return qtd;
    }

    int countEvensOnStack(Stack *pilha){
        int qtd = 0;
        for(Elemento *p = pilha->top; p != NULL; p = p->next){
            if(!(p->info & 1)){
                qtd++;
            }
        }
        return qtd;
    }

    void printDataInStack(Stack *pilha){
        Elemento *aux;
        for(aux = pilha->top; aux; aux = aux->next){
            printf("%d\n|\nv\n", aux->info);
        }
        printf("NULL\n");
    }

    bool areTwoStackEquals(Stack *p1, Stack *p2){
        Elemento *data1, *data2;
        int size1 = 0, size2 = 0;
        for(data1 = p1->top, data2 = p2->top; !data1 && !data2; data1 = data1->next, data2 = data2->next){
            size1++, size2++;
            if(data1->info != data2->info){
                return false;
            }
        }

        if(!data1 && data2){
            printf("Pilha 1 e menor que a pilha 2");
            return false;
        }

        if(data1 && !data2){
            printf("Pilha 2 e menor que a pilha 1");
            return false;
        }

        return true;
    }

    void freeDataInStack(Stack *pilha){
        Elemento *aux, *tmp;
        for(aux = pilha->top; aux; aux = tmp){
            tmp = aux->next;
            free(aux);
            pilha->top = tmp;
        }
    }

    Queue *createQueue(void){
        Queue *fila = (Queue *) malloc(sizeof(Queue));
        if(fila){
            fila->last = fila->first = NULL;
        }
        return fila;
    }

    void addInQueue(Queue *fila){
        Elemento *elemToAdd = (Elemento *) malloc(sizeof(Elemento));
        printf("Digite o dado para adicionar: ");
        scanf("%d", &elemToAdd->info);
        if(!fila->first){
            fila->last = fila->first = elemToAdd;
            return;
        }
        fila->last->next = elemToAdd;
        fila->last = elemToAdd;
        fila->last->next = NULL;
    }

    void addInQueueVal(Queue *fila, int val){
        Elemento *elemToAdd = (Elemento *) malloc(sizeof(Elemento));
        elemToAdd->info = val;
        elemToAdd->next = NULL;
        if(!fila->first){
            fila->last = fila->first = elemToAdd;
            return;
        }

        fila->last->next = elemToAdd;
        fila->last = elemToAdd;
    }

    int popQueue(Queue *pilha){
        int aux;
        Elemento *first = pilha->first;
        if(!first){
            return ERROR_VALUE;
        }
        aux = first->info;
        pilha->first = first->next;
        free(first);
        return aux;
    }

    void printDataInQueue(Queue *fila){
        Elemento *elem;
        for(elem = fila->first; elem; elem = elem->next){
            printf("%d->", elem->info);
        }
        printf("NULL\n");
    }

    void freeDataInQueue(Queue *fila){
        Elemento *aux = fila->first;
        while(aux){
            fila->first = aux->next;
            free(aux);
            aux = fila->first;
        }
    }

    Queue *copyQueue(Queue *fila){
        Queue *newQueue = createQueue();
        for(Elemento *p = fila->first; p != NULL; p = p->next){
            addInQueueVal(newQueue, p->info);
        }
        return newQueue;
    }

    void showQueueInfo(Queue *fila){
        int maior = 0, menor = 999, tmp= 0, i = 0;
        float media;
        for(Elemento *p = fila->first; p != NULL; p = p->next, i++){
            if(p->info > maior){
                maior = p->info;
            }

            if(p->info < menor){
                menor = p->info;
            }
            tmp += p->info;
        }

        media = tmp/i;
        printf("Media: %.2f. Maior: %i. Menor: %i", media, maior, menor);
    }

    int countOddsOnQueue(Queue *fila){
        int qtd = 0;
        for(Elemento *p = fila->first;p;p=p->next){
            if(p->info&1){
                qtd++;
            }
        }
        return qtd;
    }

    int countEvensOnQueue(Queue *fila){
        int qtd = 0;
        for(Elemento *p = fila->first; p; p = p->next){
            if(!(p->info&1)){
                qtd++;
            }
        }
        return qtd;
    }

    void showEvenInStack(Stack *p1){
        for(Elemento *p = p1->top; p; p = p->next){
            if(!(p->info&1)){
                printf("%i\n|\nV\n", p->info);
            }
        }
    }

    void compareStackAndQueue(Stack *pilha, Queue *fila){
        int inBothStructures[5] = {-1, -1, -1, -1, -1}, j;

    }

    void showMenu1(Stack *p1){
        int opc = -1, num;
        while(1){
            printf("1- Cadastrar numero\n2- Mostrar numeros pares\n3- Excluir numero\n4- Sair\n");
            scanf("%i", opc);
            switch(opc){
            case 1:
                pushInStack(p1);
                break;
            case 2:
                showEvenInStack(p1);
                break;
            case 3:
                printf("Digite o numero para tirar: ");
                scanf("%d", &num);
                if(num != p1->top){
                    printf("Nao e possivel retirar numero do topo\n");
                    break;
                }
                popStack(p1);
            case 4:
                return;
            default:
                printf("Opcao invalidada! Escolha outra\n");
            }
        }
    }
