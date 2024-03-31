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

celula* cria_lista(){
    celula *le = malloc(sizeof(celula));
    le->prox = NULL;
    return le;
}

void insere (int x, celula *le){
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

int main(){
    celula *le = cria_lista();
    insere(5, le);
    insere(4, le);
    insere(3, le);
    insere(2, le);
    insere(1, le);

    insere_antes(le, 999, 4);
    insere_antes(le, 777, 17);


    printf("Imprime: \n");
    imprime(le);

    printf("Imprime Recursivo: \n");
    imprime_rec(le);

    return 0;
}