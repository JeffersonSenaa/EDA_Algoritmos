#include <stdio.h>
#include <time.h>

typedef struct MediaDelay
{
    char companhia[10];
    int delay;
    int num;
};MediaDelay;


int main(){
    FILE *fp, *fpNovo;    //Ponteiro dos arquivo
    clock_t start, end;   //VAriavel que guarda o valor do tempo de execução em milissegundos
    char col2[2];
    int col1, col3;

    start =clock();     //Inicio do tempo de execução
    fp = fopen("Airlines.csv", "r");    //Função para abrir o arquivo
    if(fp == NULL){     //Condição para confirmar abertura do arquivo
        printf("Falha ao abrir o arquivo!\n");
    }
    else{
        printf("Arquivo aberto com sucesso!\n");
    }


    struct MediaDelay dados;

    while(fscanf(fp, "%d, %s, %d\n", &dados.num, dados.companhia, &dados.delay) != EOF){
     //   printf("%s", dados.delay);
    }
    printf("Valor do ID: %d\n", dados.num);
    printf("Valor da Companhia: %s\n", dados.companhia);
    printf("Valor do Delay: %d\n", dados.delay);

    fclose(fp);         //Fecha o Arquivo
    end = clock();      //Fim do tempo de execução
}