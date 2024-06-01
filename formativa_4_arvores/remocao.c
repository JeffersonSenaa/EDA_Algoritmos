#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

no* criar_no(int chave) {
    no* novo_no = (no*)malloc(sizeof(no));
    if (!novo_no) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    novo_no->chave = chave;
    novo_no->esq = novo_no->dir = NULL;
    return novo_no;
}

no* encontrar_maximo(no* raiz) {
    while (raiz->dir != NULL) {
        raiz = raiz->dir;
    }
    return raiz;
}

no* remover(no* raiz, int chave) {
    if (raiz == NULL) {
        return NULL;
    }

    if (chave < raiz->chave) {
        raiz->esq = remover(raiz->esq, chave);
    } else if (chave > raiz->chave) {
        raiz->dir = remover(raiz->dir, chave);
    } else {
        if (raiz->esq == NULL) {
            no* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            no* temp = raiz->esq;
            free(raiz);
            return temp;
        }
        no* temp = encontrar_maximo(raiz->esq);
        raiz->chave = temp->chave;
        raiz->esq = remover(raiz->esq, temp->chave);
    }
    return raiz;
}