#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int  dado;
    struct celula *prox;
}celula;

void insere_inicio (celula *le, int x){
    celula *nova = malloc(sizeof(celula));
    nova->prox = le->prox;
    nova->dado = x;
    le->prox = nova;
}

void insere_antes(celula *le, int x, int y){
    celula *p = le;
    celula *q = le->prox;
    celula *nova = malloc(sizeof(celula));
    nova->dado = x;
    while(q != NULL && q->dado != y){
        p = q;
        q = q->prox;
    }
    if(q == NULL) {
        nova->prox = q;
        p->prox = nova;
    }
    nova->prox = q;
    p->prox = nova;
}