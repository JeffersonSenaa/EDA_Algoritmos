#include <stdio.h>
#include <stdlib.h>

void intercala(int *v, int e, int d, int m) {
    int *w = malloc((d - e + 1) * sizeof(int));
    int i = e, j = m + 1, k = 0;
    while (i <= m && j <= d) {
        if (v[i] < v[j]) {
            w[k] = v[i];
            i++;
        } else {
            w[k] = v[j];
            j++;
        }
        k++;
    }
    while (i <= m) {
        w[k] = v[i];
        k++;
        i++;
    }
    while (j <= d) {
        w[k] = v[j];
        k++;
        j++;
    }
    for (k = 0, i = e; i <= d; i++, k++) {
        v[i] = w[k];
    }
    free(w);
}

void mergeSort(int *v, int e, int d){
    int m = (e + d)/2;
    if(e < d){
        mergeSort(v, e, m);
        mergeSort(v, m+1, d);
        intercala(v, e, d, m);
    }

}

int main(){
    int v[] = {2, 4, 6, 0, 3, 7, 1, 5};
    
    mergeSort(v, 0, 7);

    for(int i = 0; i < 8; i++){
        printf("%d ", v[i]);
    }
    puts("\n");

    return 0;
}