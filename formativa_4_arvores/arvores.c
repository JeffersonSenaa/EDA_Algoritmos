#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore binária
typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função para criar um novo nó com a chave x
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

// Função para inserir o valor x na árvore binária de busca com raiz r
no* inserir(no* r, int x) {
    // Se a árvore estiver vazia, retorna um novo nó
    if (r == NULL) {
        return criarNo(x);
    }

    // Caso contrário, percorre a árvore recursivamente
    if (x < r->chave) {
        r->esq = inserir(r->esq, x);
    } else if (x > r->chave) {
        r->dir = inserir(r->dir, x);
    }
    // Se x == r->chave, não faz nada, pois chaves duplicadas não são permitidas

    return r;
}

int altura(no *r) {
    if (r == NULL) {
        return 0; // Altura de uma árvore vazia é 0
    } else {
        int he = altura(r->esq);
        int hd = altura(r->dir);
        if (he > hd) {
            return he + 1;
        } else {
            return hd + 1;
        }
    }
}

// Função para imprimir a árvore em ordem (para verificação)
void imprimirEmOrdem(no* r) {
    if (r != NULL) {
        imprimirEmOrdem(r->esq);
        printf("%d ", r->chave);
        imprimirEmOrdem(r->dir);
    }
}

int main() {
    no* raiz = NULL;  // Inicializa a árvore como vazia

    // Insere valores na árvore
    raiz = inserir(raiz, 9);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 1);

    // Imprime a árvore em ordem
    printf("Árvore em ordem: ");
    imprimirEmOrdem(raiz);
    printf("\n");

    int h = altura(raiz);

    printf("%d\n", h);


    return 0;
}
