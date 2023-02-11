#include <stdio.h>
#include <time.h>
#include <string.h>

int main(){
    FILE *fp, *fpNovo;    //Ponteiro dos arquivo
    clock_t start, end;   //VAriavel que guarda o valor do tempo de execução em milissegundos
    char col2[100];
    int col1, col3;

    start =clock();     //Inicio do tempo de execução
    fp = fopen("Airlines.csv", "r");    //Função para abrir o arquivo

    if(fp == NULL){     //Condição para confirmar abertura do arquivo
        printf("Falha ao abrir o arquivo!\n");
    }
    else{
        printf("Arquivo aberto com sucesso!\n");
    }

    while(fscanf(fp, "%d, %s, %d", &col1, &col2, &col3) == EOF){
            printf("%d, %s, %d", col1, col2, col3);
        }

    printf("%s, %d", col2, col3);
  
    fclose(fp);         //Fecha o Arquivo
    end = clock();      //Fim do tempo de execução
}