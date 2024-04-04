#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int  dado;
    struct celula *prox;
}celula;

void imprime(celula *le){
    for (celula *p = le->prox; p != NULL; p = p->prox){
        printf("%d -> ", p->dado);
    }
    printf("NULL\n");
}

void imprime_rec (celula *le){
    celula *p = le->prox;
    if(p != NULL){
        printf("%d -> ", p->dado);
        imprime_rec(p);
    }
    else{
        printf("NULL\n");
    }
}