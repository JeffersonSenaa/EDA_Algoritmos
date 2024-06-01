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

void em_ordem(no* raiz) {
    Pilha* pilha = NULL;
    no* atual = raiz;

    while (!pilha_vazia(pilha) || atual != NULL) {
        if (atual != NULL) {
            empilhar(&pilha, atual);
            atual = atual->esq;
        } else {
            atual = desempilhar(&pilha);
            printf("%d ", atual->dado);
            atual = atual->dir;
        }
    }
}

no* novo_no(int dado) {
    no* n = (no*)malloc(sizeof(no));
    n->dado = dado;
    n->esq = n->dir = NULL;
    return n;
}
