#include <stdio.h>
#include <time.h>

typedef struct MediaDelay
{
    char companhia[2];  //Receber o valor das companhias
    int delay;          //Receber o valor dos atrasos
    int num;            //Receber a posicao no arquivo
};MediaDelay;


int main(){
    FILE *fp, *fpNovo;    //Ponteiro dos arquivo
    clock_t start, end;   //VAriavel que guarda o valor do tempo de execução em milissegundos
    char next[2];
    char *verifica;

    start =clock();     //Inicio do tempo de execução
    fp = fopen("Airlines.csv", "r");    //Função para abrir o arquivo
    if(fp == NULL){     //Condição para confirmar abertura do arquivo
        printf("Falha ao abrir o arquivo!\n");
        fclose(fp);
    }

    struct MediaDelay dados[10];

    int tCO;
    int aCO;
    int i = 0;

    while(fscanf(fp, "%d, %[^,], %d\n", &dados[i].num, dados[i].companhia, &dados[i].delay) != EOF){
        //Função para percorrer todo o arquivo
        if((dados[i].companhia[0] == 'C') && (dados[i].companhia[1] == 'O')){
            tCO++;
            if(dados[i].delay == 1){
                aCO++;
            }
        
        }
    }
    printf("Valor do ID: %d\n", dados[1].num);
    printf("Valor da Companhia: %s\n", dados[1].companhia);
    printf("Valor do Delay: %d\n", dados[1].delay);

    fclose(fp);         //Fecha o Arquivo
    end = clock();      //Fim do tempo de execução
}