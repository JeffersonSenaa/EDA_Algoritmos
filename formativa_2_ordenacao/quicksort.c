#include <stdio.h>
#include <stdlib.h>

int troca(int *v, int a, int b){
    if(a != b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
    }
}

int separa(int *v, int p, int r){
    int c = v[r]; //pivo
    int j = p;
    for (int k = p; k < r; ++k){
        if (v[k] < c || (v[k] == c && v[j] < c)) { 
                troca(v, j, k);
                ++j;
            }
    }
    troca(v, j, r);
    return j;
}

void quicksort(int *v, int p, int r){
    if(p < r){
        int j = separa(v, p, r);
        quicksort(v, p, j-1);
        quicksort(v, j+1, r);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int *v = malloc(n * sizeof(int));
    for(int i=0; i < n; i++){
        scanf("%d", &v[i]);
    }
    quicksort(v, 0, n-1);
    for(int i=0; i < n; i++){
        printf(" %d", v[i]);
    }
    puts("");
    free(v);
    return 0;
}