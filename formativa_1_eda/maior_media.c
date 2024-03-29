#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int sizeV, sum;
    bool found = false;
    scanf("%d", &sizeV);
    int *v = malloc(sizeV * sizeof(int));
    for(int i=0; i < sizeV; i++){
        scanf("%d", &v[i]);
        sum += v[i];
    }
    int average = sum/sizeV;
    for(int i=0; i < sizeV; i++){
        if(v[i] > average){
            printf("%d ", v[i]);
            found = true;
        }
    }
    if(!found){
        printf("0");
    }
    puts("");
    return 0;
}