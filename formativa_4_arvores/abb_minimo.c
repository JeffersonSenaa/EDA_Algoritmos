#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

no* criar_no(int chave) {
    no* novo_no = (no*)malloc(sizeof(no));
    novo_no->chave = chave;
    novo_no->esq = novo_no->dir = NULL;
    return novo_no;
}

no* inserir(no* r, int chave) {
    if (r == NULL) {
        return criar_no(chave);
    }
    if (chave < r->chave) {
        r->esq = inserir(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = inserir(r->dir, chave);
    }
    return r;
}

no* minimo(no* r) {
    if (r == NULL) {
        return NULL;
    }
    no* atual = r;
    while (atual->esq != NULL) {
        atual = atual->esq;
    }
    return atual;
}

