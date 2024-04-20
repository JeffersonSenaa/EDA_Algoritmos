#include <stdio.h>

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
    int v[10] = {3, 2, 5, 3, 1, 3, 7, 6, 9, 4};

    quicksort(v, 0, 9);

    for(int i=0; i < 10; i++){
        printf("%d ", v[i]);
    }
    puts("");

    return 0;

}