#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define  key(A) (A.media) //acessar a posição e retornar

typedef struct MediaDelay
{
    int id;            //Receber a posição no arquivo
    char companhia[2]; //Receber o valor das companhias
    int delay;         //Receber o valor dos atrasos
} MediaDelay;

typedef struct nomeComp{
    int media;
    char companhia[3];
}nomeComp;

int separa (nomeComp *v, int p, int r) {
    int c = key(v[r]); // pivô
    nomeComp t;
    int j = p;
    
    for (int k = p; k < r; ++k)
        if (key(v[k]) <= c) {
            t = v[j], v[j] = v[k], v[k] = t;
            ++j;
        }
    t = v[j], v[j] = v[r], v[r] = t;
    return j;    
}

void quicksort (nomeComp *v, int p, int r) {
    if (p < r) {
        int j = separa (v, p, r);
        quicksort (v, p, j-1);
        quicksort (v, j+1, r);
    }
}

int main(){
    struct MediaDelay dados[539384];
    FILE *fp, *fpNovo;   //Ponteiro dos arquivos
    clock_t start, end; //Variável que guarda o valor do tempo de execução em milissegundos
    double cpu_time_used;
    //Variável que guarda total de voos de cada companhia
    int tCO = 0, tMQ = 0, tAA = 0, tWN = 0, t9E = 0, tOO = 0, tAS = 0, tHA = 0, tDL = 0, tF9 = 0, tEV = 0, tUA = 0, tFL = 0, tUS = 0, tOH = 0, tXE = 0, tYV = 0, tB6 = 0;
    //Variável que guarda quantos voos atrasaram de cada companhia
    int aCO = 0, aMQ = 0, aAA = 0, aWN = 0, a9E = 0, aOO = 0, aAS = 0, aHA = 0, aDL = 0, aF9 = 0, aEV = 0, aUA = 0, aFL = 0, aUS = 0, aOH = 0, aXE = 0, aYV = 0, aB6 = 0;
    //Variável que guarda a média de cada companhia
    float mCO, mMQ, mAA, mWN, m9E, mOO, mAS, mHA, mDL, mF9, mEV, mUA, mFL, mUS, mOH, mXE, mYV, mB6;
    int i;
    double tempogasto;


    start = clock();                    //Inicio do tempo de execução
    fp = fopen("Airlines.csv", "r");    //Função para abrir o arquivo
    fpNovo = fopen("AirlinesOrden.csv", "w");     //Função para abrir o arquivo
    if(fp == NULL && fpNovo == NULL) {  //Condição para confirmar abertura dos arquivos
        printf("Falha ao abrir os arquivos!\n");
    }

    i = 0;   //Função para salvar id, companhia, delay de todo o arquivo 
    while(fscanf(fp, "%d, %[^,], %d\n", &dados[i].id, dados[i].companhia, &dados[i].delay) != EOF) {
        if((dados[i].companhia[0] == 'C') && (dados[i].companhia[1] == 'O')){
                tCO++;
                if(dados[i].delay == 1){
                 aCO++;
            }
        } else if((dados[i].companhia[0] == 'M') && (dados[i].companhia[1] == 'Q')){
             tMQ++;
                if(dados[i].delay == 1){
                   aMQ++;
        }
        } else if((dados[i].companhia[0] == 'A') && (dados[i].companhia[1] == 'A')){
                tAA++;
                if(dados[i].delay == 1){
                  aAA++;
        }
        } else if((dados[i].companhia[0] == 'W') && (dados[i].companhia[1] == 'N')){
             tWN++;
                if(dados[i].delay == 1){
                   aWN++;
        }
        } else if((dados[i].companhia[0] == '9') && (dados[i].companhia[1] == 'E')){
                t9E++;
                if(dados[i].delay == 1){
                    a9E++;
        }
        } else if((dados[i].companhia[0] == 'O') && (dados[i].companhia[1] == 'O')){
                tOO++;
                if(dados[i].delay == 1){
                    aOO++;
        }
        } else if((dados[i].companhia[0] == 'A') && (dados[i].companhia[1] == 'S')){
                tAS++;
                 if(dados[i].delay == 1){
                    aAS++;
        }
        } else if((dados[i].companhia[0] == 'H') && (dados[i].companhia[1] == 'A')){
             tHA++;
             if(dados[i].delay == 1){
                  aHA++;
        }
        } else if((dados[i].companhia[0] == 'D') && (dados[i].companhia[1] == 'L')){
              tDL++;
               if(dados[i].delay == 1){
                 aDL++;
        }
        } else if((dados[i].companhia[0] == 'F') && (dados[i].companhia[1] == '9')){
             tF9++;
              if(dados[i].delay == 1){
                aF9++;
        }
        } else if((dados[i].companhia[0] == 'E') && (dados[i].companhia[1] == 'V')){
              tEV++;
               if(dados[i].delay == 1){
                aEV++;
        }
        } else if((dados[i].companhia[0] == 'U') && (dados[i].companhia[1] == 'A')){
               tUA++;
                   if(dados[i].delay == 1){
                       aUA++;
        }
        } else if((dados[i].companhia[0] == 'F') && (dados[i].companhia[1] == 'L')){
              tFL++;
               if(dados[i].delay == 1){
                aFL++;
        }
        } else if((dados[i].companhia[0] == 'U') && (dados[i].companhia[1] == 'S')){
               tUS++;
                   if(dados[i].delay == 1){
                    aUS++;
        }
        } else if((dados[i].companhia[0] == 'O') && (dados[i].companhia[1] == 'H')){
               tOH++;
                if(dados[i].delay == 1){
                 aOH++;
        }
        } else if((dados[i].companhia[0] == 'X') && (dados[i].companhia[1] == 'E')){
              tXE++;
                  if(dados[i].delay == 1){
                      aXE++;
        }
        } else if((dados[i].companhia[0] == 'Y') && (dados[i].companhia[1] == 'V')){
               tYV++;
                   if(dados[i].delay == 1){
                       aYV++;
        }
        } else if((dados[i].companhia[0] == 'B') && (dados[i].companhia[1] == '6')){
                tB6++;
                   if(dados[i].delay == 1){
                       aB6++;
        }
        }
        i++;
    }
    //calcular a média de cada companhia
    mCO = aCO*pow(tCO,-1)*pow(10, 2);
    mMQ = aMQ*pow(tMQ, -1)*pow(10, 2);
    mAA = aAA*pow(tAA,-1)*pow(10, 2);
    mWN = aWN*pow(tWN,-1)*pow(10, 2);
    m9E = a9E*pow(t9E, -1)*pow(10, 2);
    mOO = aOO*pow(tOO, -1)*pow(10, 2);
    mAS = aAS*pow(tAS, -1)*pow(10, 2);
    mHA = aHA*pow(tHA, -1)*pow(10, 2);
    mDL = aDL*pow(tDL, -1)*pow(10, 2);
    mF9 = aF9*pow(tF9, -1)*pow(10, 2);
    mEV = aEV*pow(tEV, -1)*pow(10, 2);
    mUA = aUA*pow(tUA, -1)*pow(10, 2);
    mFL = aFL*pow(tFL, -1)*pow(10, 2);
    mUS = aUS*pow(tUS, -1)*pow(10, 2);
    mOH = aOH*pow(tOH, -1)*pow(10, 2);
    mXE = aXE*pow(tXE, -1)*pow(10, 2);
    mYV = aYV*pow(tYV, -1)*pow(10, 2);
    mB6 = aB6*pow(tB6, -1)*pow(10, 2);

    //Casting dos valores em float para inteiros, para serem ordenados
    int medCO = (int)mCO;
    int medMQ = (int)mMQ;
    int medAA = (int)mAA;
    int medWN = (int)mWN;
    int med9E = (int)m9E;
    int medOO = (int)mOO;
    int medAS = (int)mAS;
    int medHA = (int)mHA;
    int medDL = (int)mDL;
    int medF9 = (int)mF9;
    int medEV = (int)mEV;
    int medUA = (int)mUA;
    int medFL = (int)mFL;
    int medUS = (int)mUS;
    int medOH = (int)mOH;
    int medXE = (int)mXE;
    int medYV = (int)mYV;
    int medB6 = (int)mB6;

    nomeComp medias[] = {{medCO,"CO"}, {medMQ,"MQ"}, {medAA, "AA"}, {medWN, "WN"}, {med9E, "9E"}, {medOO, "OO"}, {medAS, "AS"}, {medHA, "HA"}, {medDL, "DL"}, {medF9, "F9"}, {medEV, "EV"}, {medUA, "UA"}, {medFL, "FL"}, {medUS, "US"}, {medOH, "OH"}, {medXE, "XE"}, {medYV, "YV"}, {medB6, "B6"}};   //ordena o vetor de

    int tam = sizeof(medias) / sizeof(medias[0]);
    int j; 

    quicksort(medias, 0, tam-1);

    for(j=0; j < tam; j++){
        fprintf(fpNovo, "%s %d\n", medias[j].companhia, medias[j].media);
    }

    //Fecha os Arquivos
    fclose(fp);                         
    

    //Fim do tempo de execução
    end = clock();    
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
     fprintf(fpNovo, "O tempo de execução foi %f segundos\n", cpu_time_used);
     fprintf(fpNovo, "O metodo de ordenação utilizado foi de Quick Sort. \n"); 

    fclose(fpNovo);
    
    
    return 0;                 
}