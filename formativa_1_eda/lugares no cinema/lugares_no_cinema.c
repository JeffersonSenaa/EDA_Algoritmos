#include <stdio.h>
#include <string.h>

int converter_letra(char letra){
    if(letra >= 'A' || letra <= 'T'){
        return letra - 'A';
    }
}

char converter_numero(int numero){
    if(numero >= 0 && numero <= 19){
        return 'A' + numero;
    }
}

int main(){
    int f, l, num, num_letra;
    char letra = ' ';
    scanf("%d %d\n", &f, &l);
    printf("  ");

    char cinema[f][l][3];

    for(int i = 0; i < f; i++){
        for(int j=0; j < l; j++){
            strcpy(cinema[i][j], "--");
        }
    }

    while (scanf(" %c %d", &letra, &num) != EOF) { 
        num_letra = converter_letra(letra);
        strcpy(cinema[num_letra][num - 1], "XX");
    }

    printf("  ");
    for(int j = 0; j < l; j++){
    printf("%02d  ", j + 1);
    }
    puts("");
    for(int i = f-1; i >= 0; i--){
        char num_fileira = converter_numero(i);
        printf("%c", num_fileira);
        for(int j = 0; j < l; j++){
            printf(" %s ", cinema[i][j]);
        }
        puts("");
    }

    return 0;
}