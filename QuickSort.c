#include <stdio.h>
#include <time.h>

int abreArquivo(FILE *fp, char arquivo[13], char f[2]){
    fp = fopen(arquivo, f);    //Função para abrir o arquivo

    if(fp == NULL){     //Condição para confirmar abertura do arquivo
        printf("Falha ao abrir o arquivo!\n");
    }
    else{
        printf("Arquivo aberto com sucesso!\n");
    }
}

int main(){
    FILE *fp, *fpNovo;    //Ponteiro dos arquivo
    clock_t start, end;   //VAriavel que guarda o valor do tempo de execução em milissegundos

    start =clock();     //Inicio do tempo de execução
    abreArquivo(fp, "Airlines.csv", "r");      //Chamada a função para abrir o arquivo

    end = clock();      //Fim do tempo de execução
}