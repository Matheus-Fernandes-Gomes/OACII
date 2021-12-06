#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vet[16][10];
int le_arquivo(char* nomeArq){
    FILE *arq;
    int aux,aux2;
    arq = fopen(nomeArq, "r");
    if(arq!=NULL){
        int c;
        while((c=fgetc(arq))!=EOF){
            //vet[aux][aux2]=c-'0';
            vet[aux][aux2]=c;
            printf("%c",vet[aux][aux2]);
            aux++;
            if(aux==15){
                aux=0;
                aux2=aux2+1;
            }
        }
        fclose(arq);
    }else printf("erro ao abrir o arquivo");
    return(aux2);
}

void and(int pcCount){
    for(int i=5;i<9;i++){
        if((vet[i][pcCount]*vet[i+4][pcCount])!=0){
            vet[i+8][pcCount]=1;
        }
        else{
            vet[i+8][pcCount]=0;
        }
    }

}

void or(int pcCount){
    for(int i=5;i<9;i++){
        if((vet[i][pcCount]+vet[i+4][pcCount])!=0){
            vet[i+8][pcCount]=1;
        }
        else{
            vet[i+8][pcCount]=0;
        }
    }

}

void imprime(aux){
     for(int j=0;j<=aux;j++){
        for(int i=0;i<=15;i++){
        printf("%c",vet[i][j]);
    }
    printf("\n");
    }
}

int main()
{
    int aux,pcCount=0;

    aux=le_arquivo("Instruocoes.txt");
    while(pcCount<=aux){
    if((vet[0][pcCount]==0)&&(vet[1][pcCount]==0)&&(vet[2][pcCount]==1)&&(vet[3][pcCount]==1)){
        printf("true");
        and(pcCount);
    }
    else if((vet[0][pcCount]=='0')&&(vet[1][pcCount]=='1')&&(vet[2][pcCount]=='0')&&(vet[3][pcCount]=='0')){
        printf("true");
        or(pcCount);
    }


    pcCount++;
    }
    imprime(aux);

    return 0;
}
