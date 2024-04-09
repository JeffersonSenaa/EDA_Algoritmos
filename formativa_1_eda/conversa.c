#include <stdio.h>

int main() {
    int n, m; 
    int x, y; 
    int k; 
    int monitora;
    int incremento = 0;
    int px = 0, py = 0; 

    scanf("%d %d", &n, &m); 
    scanf("%d %d", &x, &y); 
    scanf("%d", &k); 

    for (int i = 0; i < k; i++) {
        scanf("%d", &monitora); 
        switch (monitora) {
            case 1: py++; break; // Norte
            case 2: py--; break; // Sul
            case 3: px++; break; // Leste
            case 4: px--; break; // oeste
        }
        if(py <= y+1 && 
           py >= y-1 &&
           px <= x+1 &&
           px >= x-1)
            incremento++;
    }
    printf("%d\n", incremento);
    return 0;
}
