#include <stdio.h>

int main() {
    int n, m, p;
    scanf("%d %d", &n, &m); 
    scanf("%d", &p); 

    int pa_x = 1, pa_y = 1; 
    int pb_x = n, pb_y = m; 
    int step; 

    for (step = 1; step <= p; step++) {
        int dir_pa, dir_pb;
        scanf("%d %d", &dir_pa, &dir_pb); 

        switch (dir_pa) {
            case 1: pa_y++; break; 
            case 2: pa_y--; break; 
            case 3: pa_x++; break; 
            case 4: pa_x--; break; 
        }

        if (pa_x < 1 || pa_x > n || pa_y < 1 || pa_y > m) {
            printf("PA saiu na posicao (%d,%d) no passo %d\n", pa_x, pa_y, step);
            return 0; 
        }

        switch (dir_pb) {
            case 1: pb_y++; break; 
            case 2: pb_y--; break; 
            case 3: pb_x++; break; 
            case 4: pb_x--; break; 
        }

        if (pb_x < 1 || pb_x > n || pb_y < 1 || pb_y > m) {
            printf("PB saiu na posicao (%d,%d) no passo %d\n", pb_x, pb_y, step);
            return 0;
        }

        if (pa_x == pb_x && pa_y == pb_y) {
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", pa_x, pa_y, step);
            return 0; 
        }
    }

    printf("Nao se encontraram\n");

    return 0;
}
