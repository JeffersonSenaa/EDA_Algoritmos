#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char chave;
    struct no *esq, *dir;
} no;

no* criar_no(char chave) {
    no* novo_no = (no*)malloc(sizeof(no));
    novo_no->chave = chave;
    novo_no->esq = novo_no->dir = NULL;
    return novo_no;
}

no* construir_arvore(char* pre_fixo, char* in_fixo, int in_inicio, int in_fim, int* pre_indice) {
    if (in_inicio > in_fim) {
        return NULL;
    }

    char chave_atual = pre_fixo[*pre_indice];
    (*pre_indice)++;

    no* raiz = criar_no(chave_atual);

    if (in_inicio == in_fim) {
        return raiz;
    }

    int in_indice;
    for (in_indice = in_inicio; in_indice <= in_fim; in_indice++) {
        if (in_fixo[in_indice] == chave_atual) {
            break;
        }
    }

    raiz->esq = construir_arvore(pre_fixo, in_fixo, in_inicio, in_indice - 1, pre_indice);
    raiz->dir = construir_arvore(pre_fixo, in_fixo, in_indice + 1, in_fim, pre_indice);

    return raiz;
}

void percurso_pos_fixo(no* raiz) {
    if (raiz == NULL) {
        return;
    }
    percurso_pos_fixo(raiz->esq);
    percurso_pos_fixo(raiz->dir);
    printf("%c", raiz->chave);
}

int main() {
    int C;
    scanf("%d", &C);

    while (C--) {
        int N;
        char pre_fixo[53], in_fixo[53];
        scanf("%d %s %s", &N, pre_fixo, in_fixo);

        int pre_indice = 0;
        no* raiz = construir_arvore(pre_fixo, in_fixo, 0, N - 1, &pre_indice);

        percurso_pos_fixo(raiz);
        printf("\n");
    }

    return 0;
}
