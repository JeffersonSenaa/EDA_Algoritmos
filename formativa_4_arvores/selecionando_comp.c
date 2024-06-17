#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} MinHeap;

typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} MaxHeap;

MinHeap* criaMinHeap(int capacidade) {
    MinHeap *heap = (MinHeap*) malloc(sizeof(MinHeap));
    heap->dados = (int*) malloc(capacidade * sizeof(int));
    heap->tamanho = 0;
    heap->capacidade = capacidade;
    return heap;
}

MaxHeap* criaMaxHeap(int capacidade) {
    MaxHeap *heap = (MaxHeap*) malloc(sizeof(MaxHeap));
    heap->dados = (int*) malloc(capacidade * sizeof(int));
    heap->tamanho = 0;
    heap->capacidade = capacidade;
    return heap;
}

void destroiMinHeap(MinHeap *heap) {
    free(heap->dados);
    free(heap);
}

void destroiMaxHeap(MaxHeap *heap) {
    free(heap->dados);
    free(heap);
}

void troca(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapifica(MinHeap *heap, int idx) {
    int menor = idx;
    int esquerda = 2 * idx + 1;
    int direita = 2 * idx + 2;

    if (esquerda < heap->tamanho && heap->dados[esquerda] < heap->dados[menor])
        menor = esquerda;

    if (direita < heap->tamanho && heap->dados[direita] < heap->dados[menor])
        menor = direita;

    if (menor != idx) {
        troca(&heap->dados[idx], &heap->dados[menor]);
        minHeapifica(heap, menor);
    }
}

void insereMinHeap(MinHeap *heap, int chave) {
    if (heap->tamanho == heap->capacidade) {
        heap->capacidade *= 2;
        heap->dados = (int*) realloc(heap->dados, heap->capacidade * sizeof(int));
    }
    heap->tamanho++;
    int i = heap->tamanho - 1;
    heap->dados[i] = chave;

    while (i != 0 && heap->dados[(i - 1) / 2] > heap->dados[i]) {
        troca(&heap->dados[i], &heap->dados[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extraiMin(MinHeap *heap) {
    if (heap->tamanho <= 0)
        return INT_MAX;
    if (heap->tamanho == 1) {
        heap->tamanho--;
        return heap->dados[0];
    }

    int raiz = heap->dados[0];
    heap->dados[0] = heap->dados[heap->tamanho - 1];
    heap->tamanho--;
    minHeapifica(heap, 0);

    return raiz;
}

void maxHeapifica(MaxHeap *heap, int idx) {
    int maior = idx;
    int esquerda = 2 * idx + 1;
    int direita = 2 * idx + 2;

    if (esquerda < heap->tamanho && heap->dados[esquerda] > heap->dados[maior])
        maior = esquerda;

    if (direita < heap->tamanho && heap->dados[direita] > heap->dados[maior])
        maior = direita;

    if (maior != idx) {
        troca(&heap->dados[idx], &heap->dados[maior]);
        maxHeapifica(heap, maior);
    }
}

void insereMaxHeap(MaxHeap *heap, int chave) {
    if (heap->tamanho == heap->capacidade) {
        heap->capacidade *= 2;
        heap->dados = (int*) realloc(heap->dados, heap->capacidade * sizeof(int));
    }
    heap->tamanho++;
    int i = heap->tamanho - 1;
    heap->dados[i] = chave;

    while (i != 0 && heap->dados[(i - 1) / 2] < heap->dados[i]) {
        troca(&heap->dados[i], &heap->dados[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extraiMax(MaxHeap *heap) {
    if (heap->tamanho <= 0)
        return INT_MIN;
    if (heap->tamanho == 1) {
        heap->tamanho--;
        return heap->dados[0];
    }

    int raiz = heap->dados[0];
    heap->dados[0] = heap->dados[heap->tamanho - 1];
    heap->tamanho--;
    maxHeapifica(heap, 0);

    return raiz;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    MinHeap *tuboA = criaMinHeap(n);
    MaxHeap *tuboB = criaMaxHeap(n);
    int *combinacoes = (int*) malloc(n * sizeof(int));
    int contadorCombinacoes = 0;

    for (int i = 0; i < n; i++) {
        int densidade;
        scanf("%d", &densidade);
        insereMinHeap(tuboA, densidade);
    }

    while (tuboA->tamanho > 0) {
        int minA = extraiMin(tuboA);
        if (tuboB->tamanho == 0) {
            insereMaxHeap(tuboB, minA);
        } else {
            int maxB = extraiMax(tuboB);
            if (abs(minA - maxB) <= k && abs(minA - maxB) > 0) {
                combinacoes[contadorCombinacoes++] = minA + maxB;
            } else {
                insereMaxHeap(tuboB, maxB); 
                insereMaxHeap(tuboB, minA); 
            }
        }
    }

    printf("%d\n", contadorCombinacoes);
    if (contadorCombinacoes > 0) {
        for (int i = 0; i < contadorCombinacoes; i++) {
            printf("%d ", combinacoes[i]);
        }
        printf("\n");
    }

    destroiMinHeap(tuboA);
    destroiMaxHeap(tuboB);
    free(combinacoes);

    return 0;
}
