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

void inserir(no* nos[], int pai, int filho) {
    no* novo_no = criar_no(filho);
    if (nos[pai]->esq == NULL) {
        nos[pai]->esq = novo_no;
    } else {
        nos[pai]->dir = novo_no;
    }
    nos[filho] = novo_no;
}

int altura_balanceada(no* raiz, int* altura) {
    if (raiz == NULL) {
        *altura = 0;
        return 1;
    }

    int altura_esq = 0, altura_dir = 0;
    int balanceado_esq = altura_balanceada(raiz->esq, &altura_esq);
    int balanceado_dir = altura_balanceada(raiz->dir, &altura_dir);

    *altura = (altura_esq > altura_dir ? altura_esq : altura_dir) + 1;

    if (abs(altura_esq - altura_dir) > 1) {
        return 0;
    }

    return balanceado_esq && balanceado_dir;
}

int main() {
    int N;
    scanf("%d", &N);

    no* nos[N + 1];
    for (int i = 1; i <= N; i++) {
        nos[i] = criar_no(i);
    }

    for (int i = 2; i <= N; i++) {
        int pai;
        scanf("%d", &pai);
        inserir(nos, pai, i);
    }

    int altura = 0;
    if (altura_balanceada(nos[1], &altura)) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }
    return 0;
}
