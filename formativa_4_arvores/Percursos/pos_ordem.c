#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

typedef struct Pilha {
    no* dados;
    struct Pilha* prox;
} Pilha;

void empilhar(Pilha** topo, no* n) {
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    if (!novo) {
        fprintf(stderr, "Erro de alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    novo->dados = n;
    novo->prox = *topo;
    *topo = novo;
}

no* desempilhar(Pilha** topo) {
    if (*topo == NULL) {
        return NULL;
    }
    Pilha* temp = *topo;
    no* n = temp->dados;
    *topo = (*topo)->prox;
    free(temp);
    return n;
}

int pilha_vazia(Pilha* topo) {
    return topo == NULL;
}

void pos_ordem(no* raiz) {
    if (raiz == NULL) {
        return;
    }

    Pilha* pilha1 = NULL;
    Pilha* pilha2 = NULL;

    empilhar(&pilha1, raiz);

    while (!pilha_vazia(pilha1)) {
        no* atual = desempilhar(&pilha1);
        empilhar(&pilha2, atual);

        if (atual->esq) {
            empilhar(&pilha1, atual->esq);
        }
        if (atual->dir) {
            empilhar(&pilha1, atual->dir);
        }
    }

    while (!pilha_vazia(pilha2)) {
        no* atual = desempilhar(&pilha2);
        printf("%d ", atual->dado);
    }
}

no* novo_no(int dado) {
    no* n = (no*)malloc(sizeof(no));
    n->dado = dado;
    n->esq = n->dir = NULL;
    return n;
}