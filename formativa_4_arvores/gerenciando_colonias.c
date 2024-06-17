#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char chave[11];
    struct No *esq;
    struct No *dir;
} No;

typedef struct Formiga {
    long long id;
    No *chaves;
    struct Formiga *esq;
    struct Formiga *dir;
} Formiga;

int hash(long long id, int tamanho) {
    return abs(id) % tamanho;
}

No *criaNo(const char *chave) {
    No *novoNo = (No *)malloc(sizeof(No));
    strcpy(novoNo->chave, chave);
    novoNo->esq = novoNo->dir = NULL;
    return novoNo;
}

Formiga *criaFormiga(long long id) {
    Formiga *novaFormiga = (Formiga *)malloc(sizeof(Formiga));
    novaFormiga->id = id;
    novaFormiga->chaves = NULL;
    novaFormiga->esq = novaFormiga->dir = NULL;
    return novaFormiga;
}

No *insereArvore(No *raiz, const char *chave) {
    if (raiz == NULL) {
        return criaNo(chave);
    }
    if (strcmp(chave, raiz->chave) < 0) {
        raiz->esq = insereArvore(raiz->esq, chave);
    } else if (strcmp(chave, raiz->chave) > 0) {
        raiz->dir = insereArvore(raiz->dir, chave);
    }
    return raiz;
}

int existe(No *raiz, const char *chave) {
    if (raiz == NULL) {
        return 0;
    }
    int cmp = strcmp(chave, raiz->chave);
    if (cmp == 0) {
        return 1;
    } else if (cmp < 0) {
        return existe(raiz->esq, chave);
    } else {
        return existe(raiz->dir, chave);
    }
}

Formiga *insereFormiga(Formiga *raiz, long long id) {
    if (raiz == NULL) {
        return criaFormiga(id);
    }
    if (id < raiz->id) {
        raiz->esq = insereFormiga(raiz->esq, id);
    } else if (id > raiz->id) {
        raiz->dir = insereFormiga(raiz->dir, id);
    }
    return raiz;
}

Formiga *encontra(Formiga *raiz, long long id) {
    if (raiz == NULL || raiz->id == id) {
        return raiz;
    }
    if (id < raiz->id) {
        return encontra(raiz->esq, id);
    } else {
        return encontra(raiz->dir, id);
    }
}

void gerencia(Formiga **tabelaHash, int tamanho, long long id, const char *chave) {
    int indice = hash(id, tamanho);
    if (tabelaHash[indice] == NULL) {
        tabelaHash[indice] = criaFormiga(id);
    }

    Formiga *formigaAtual = encontra(tabelaHash[indice], id);
    if (formigaAtual == NULL) {
        tabelaHash[indice] = insereFormiga(tabelaHash[indice], id);
        formigaAtual = encontra(tabelaHash[indice], id);
    }

    if (existe(formigaAtual->chaves, chave)) {
        printf("%lld\n", id);
    } else {
        formigaAtual->chaves = insereArvore(formigaAtual->chaves, chave);
    }
}

void liberaArvoreNos(No *raiz) {
    if (raiz == NULL) {
        return;
    }
    liberaArvoreNos(raiz->esq);
    liberaArvoreNos(raiz->dir);
    free(raiz);
}

void liberaArvoreFormigas(Formiga *raiz) {
    if (raiz == NULL) {
        return;
    }
    liberaArvoreFormigas(raiz->esq);
    liberaArvoreFormigas(raiz->dir);
    liberaArvoreNos(raiz->chaves);
    free(raiz);
}

int main() {
    int tamanho = 1048576;
    Formiga **tabelaHash = (Formiga **)malloc(tamanho * sizeof(Formiga *));
    for (int i = 0; i < tamanho; i++) {
        tabelaHash[i] = NULL;
    }

    long long id;
    char chave[11];
    while (scanf("%lld %10s", &id, chave) != EOF) {
        gerencia(tabelaHash, tamanho, id, chave);
    }

    for (int i = 0; i < tamanho; i++) {
        if (tabelaHash[i] != NULL) {
            liberaArvoreFormigas(tabelaHash[i]);
        }
    }
    free(tabelaHash);

    return 0;
}
