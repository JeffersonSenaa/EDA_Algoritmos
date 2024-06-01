#include <stdio.h>
#include <string.h>

#define MAX_CHARS 1001
#define ASCII_RANGE 128

typedef struct {
    int ascii;
    int frequencia;
} CaractereFrequencia;

void trocar(CaractereFrequencia *a, CaractereFrequencia *b) {
    CaractereFrequencia temp = *a;
    *a = *b;
    *b = temp;
}
void ordenarPorFrequencia(CaractereFrequencia vetor[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vetor[j].frequencia < vetor[i].frequencia ||
                (vetor[j].frequencia == vetor[i].frequencia && vetor[j].ascii < vetor[i].ascii)) {
                trocar(&vetor[j], &vetor[i]);
            }
        }
    }
}

int main() {
    char linha[MAX_CHARS];

    while (fgets(linha, MAX_CHARS, stdin) != NULL) {
        int frequencia[ASCII_RANGE] = {0};

        for (int i = 0; linha[i] != '\0' && linha[i] != '\n'; i++) {
            frequencia[(int)linha[i]]++;
        }

        CaractereFrequencia caracteresFrequencia[ASCII_RANGE];
        int tamanho = 0;
        for (int i = 0; i < ASCII_RANGE; i++) {
            if (frequencia[i] > 0) {
                caracteresFrequencia[tamanho].ascii = i;
                caracteresFrequencia[tamanho].frequencia = frequencia[i];
                tamanho++;
            }
        }

        ordenarPorFrequencia(caracteresFrequencia, tamanho);

        for (int i = 0; i < tamanho; i++) {
            printf("%d %d\n", caracteresFrequencia[i].ascii, caracteresFrequencia[i].frequencia);
        }

        printf("\n"); 
    }

    return 0;
}
