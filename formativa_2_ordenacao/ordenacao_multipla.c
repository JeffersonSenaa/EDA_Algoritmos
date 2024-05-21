#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double nota;
    int indice_i;
    int indice_j;
} Problema;

// Função de comparação para qsort
int compararProblemas(const void *a, const void *b) {
    Problema *problemaA = (Problema *)a;
    Problema *problemaB = (Problema *)b;
    
    // Ordena em ordem decrescente das notas
    if (problemaA->nota > problemaB->nota) {
        return -1;
    } else if (problemaA->nota < problemaB->nota) {
        return 1;
    } else {
        // Em caso de empate, ordena em ordem crescente dos índices i e j
        if (problemaA->indice_i != problemaB->indice_i) {
            return problemaA->indice_i - problemaB->indice_i;
        } else {
            return problemaA->indice_j - problemaB->indice_j;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int caso = 0; caso < T; caso++) {
        int M, N;
        scanf("%d %d", &M, &N);

        // Matriz para armazenar as notas dos membros
        double **notas = (double **)malloc(M * sizeof(double *));
        for (int i = 0; i < M; i++) {
            notas[i] = (double *)malloc(N * sizeof(double));
            for (int j = 0; j < N; j++) {
                scanf("%lf", &notas[i][j]);
            }
        }

        // Vetor de problemas
        Problema *problemas = (Problema *)malloc(M * N * sizeof(Problema));
        int k = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                problemas[k].nota = notas[i][j];
                problemas[k].indice_i = i + 1; // Índice começa em 1
                problemas[k].indice_j = j + 1; // Índice começa em 1
                k++;
            }
        }

        // Ordena os problemas
        qsort(problemas, M * N, sizeof(Problema), compararProblemas);

        // Imprime os problemas ordenados
        for (int i = 0; i < M * N; i++) {
            printf("%d,%d", problemas[i].indice_i, problemas[i].indice_j);
            if (i < M * N - 1) {
                printf(" ");
            }
        }
        printf("\n");

        // Libera memória alocada
        for (int i = 0; i < M; i++) {
            free(notas[i]);
        }
        free(notas);
        free(problemas);
    }

    return 0;
}
