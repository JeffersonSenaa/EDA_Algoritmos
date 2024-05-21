#include <stdio.h>
#include <stdlib.h>

#define casosDeTeste 16

int comparar(const void *a, const void *b) {
    const int *num1 = (const int *)a;
    const int *num2 = (const int *)b;
    if (*num1 > *num2) {
        return 1;
    } else if (*num1 < *num2) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    // Alocação e preenchimento da matriz
    int **matriz = malloc((casosDeTeste / 2) * sizeof(int *));
    int *vOrdenado;
    int cont = 0;
    int submissoes;
    int *vet = malloc(8 * sizeof(int));
    
    for (int i = 0; i < (casosDeTeste / 2); i++) {
        submissoes = 0;
        scanf("%d", &submissoes);
        cont += submissoes;
        vet[i] = submissoes;
        matriz[i] = malloc(submissoes * sizeof(int));
        for (int j = 0; j < submissoes; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int sum = 0;
    for (int k = 0; k < casosDeTeste / 2; k++) {
        sum += vet[k];
    }

    vOrdenado = malloc(sum * sizeof(int));
    int contador = 0;
    for (int i = 0; i < (casosDeTeste / 2); i++) {
        for (int j = 0; j < vet[i]; j++) {
            vOrdenado[contador++] = matriz[i][j];
        }
    }

    qsort(vOrdenado, sum, sizeof(int), comparar);

    // Impressão do vetor ordenado
    for (int i = 0; i < sum; i++) {
        printf("%d ", vOrdenado[i]);
    }
    printf("\n");

    // Desalocação da memória
    for (int i = 0; i < casosDeTeste / 2; i++) {
        free(matriz[i]);
    }
    free(matriz);
    free(vOrdenado);
    free(vet);

    return 0;
}
