#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

no* criarNo(int x) {
    no* novoNo = (no*)malloc(sizeof(no));
    if (novoNo == NULL) {
        perror("Erro ao alocar memória para o novo nó");
        exit(EXIT_FAILURE);
    }
    novoNo->chave = x;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

no* inserir(no* r, int x) {
    if (r == NULL) {
        return criarNo(x);
    }

    if (x < r->chave) {
        r->esq = inserir(r->esq, x);
    } else if (x > r->chave) {
        r->dir = inserir(r->dir, x);
    }

    return r;
}