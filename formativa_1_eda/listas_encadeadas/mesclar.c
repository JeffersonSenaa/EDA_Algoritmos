#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int  dado;
    struct celula *prox;
}celula;

void mescla_listas(celula *l1, celula *l2, celula *l3){
    celula *p1, *p2, *p3;
    p1 = l1->prox;
    p2 = l2->prox;
    p3 = l3;

    while (p1 != NULL && p2 != NULL)    {
        if(p1->dado <= p2->dado){
            p3->prox = p1;
            p1 = p1->prox;
        }
        else{
            p3->prox = p2;
            p2 = p2->prox;
        }
        p3 = p3->prox;
    }
    while (p1 != NULL){
        p3->prox = p1;
        p1 = p1->prox;
        p3 = p3->prox;
    }
    while (p2 != NULL){
        p3->prox = p2;
        p2 = p2->prox;
        p3 = p3->prox;
    } 
    p3->prox = NULL;
    
}