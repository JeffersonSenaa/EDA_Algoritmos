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

void remove_depois(celula *le){
    celula *aux = le->prox;
    le->prox = aux->prox;
    free(aux);
}

void remove_elemento(celula *le, int x){
    celula *p, *q;
    p = le;
    q = le->prox;
    while(q != NULL && q->dado != x){
        p = q;
        q = q->prox;
    }
    if(q != NULL){
    p->prox = q->prox;
    free(q);
    }
}

void remove_todos_elementos(celula *le, int x) {
    celula *p, *q;
    p = le;
    q = le->prox;
    while(q != NULL){
        if(q->dado == x){
            p->prox = q->prox;
            free(q);    
            q = p->prox;
        }
        else{
            p = q;
            q = q->prox;
        }
    }
}

celula *busca(celula *le, int x){
    celula *p, *q;
    p = le;
    q = le->prox;
    while(q != NULL && q->dado != x){
        p = q;
        q = q->prox;
    }
    if(q->dado == x && q != NULL){
        printf("%d", q->dado);
        return q;
    }
    else
        return NULL;
    
}

celula *busca_rec(celula *le, int x){
    celula *p, *q;
    p = le;
    q = le->prox;
    if(q == NULL)
        return NULL;
    if(q->dado == x){
        printf("%d", q->dado);
        return q;
    }
    return busca_rec(q, x);
}

void mescla_lista(celula *l1, celula *l2, celula *l3){
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

int main(){
    celula *l1 = cria_lista();
    celula *l2 = cria_lista();
    celula *l3 = cria_lista();
    insere(10, l1);
    insere(9, l1);
    insere(7, l1);
    insere(1, l1);
    insere(8, l2);
    insere(3, l2);
    insere(2, l2);

    mescla_lista(l1, l2, l3);

    imprime(l3);

    return 0;
}