#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include "tabuleiro.h"

#define tips 6 //Numero de tipos de cada classe das peças
#define t_pecs 108 //Numero total de peças

int crt_pec(pec_def *pec_p){

    char *let[tips] = {"A","B","C","D","E","F"};
    char *num[tips] = {"1","2","3","4","5","6"};
    char **pecs;
    
    pecs = (char **) malloc(sizeof(char **)*108);
    
    if(pecs == NULL){
        return ERRO;
    }

    for(int i = 0; i < 108;i++){

        pecs[i] = (char *) malloc(sizeof(char *)*2);
        
        if(pecs[i] == NULL){
            return ERRO;
        }
    }
    pec_p->let_tip = let;
    pec_p->num_tip = num;
    
    int ctn = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < tips; j++){
        
            for(int k = 0; k < tips; k++){
            
                char str_L[2];
                strcpy(str_L,let[j]);
                char str_N[2];
                strcpy(str_N,num[k]);
   
                strcat(str_L, str_N);

                strcpy(pecs[ctn],str_L);
                ctn++;
            }

        }
    }
    
    pec_p->pecs = pecs;

    return SUCESSO;
}

int crt_jog(jog_def *jog_j,char **pecs){

    char nome[100];
    int pontos = 0;
    char **pecs_j;

    pecs_j = (char **) malloc(sizeof(char**)*6);
    if(pecs_j == NULL){
        return ERRO;
    }
    
    for(int i = 0; i < 6; i++){
    
        pecs_j[i] = (char *) malloc(sizeof(char *)*2);
        if(pecs_j[i] == NULL){
            return ERRO;
        }
        strcpy(pecs_j[i],"--");

    }

    printf("Escreva seu nome:\n");
    fgets(nome, 100, stdin);
    

    rep_pecs(pecs_j,pecs);
    
    jog_j->nome = nome;
    jog_j->pontos = pontos;
    jog_j->pecs = pecs_j;
    return SUCESSO;
}

int rep_pecs(char **pecs_j, char **pecs){

srand(time(NULL));


for(int k = 0; k < 6; k++){
    
    if(!strcmp(pecs_j[k],"--")){

        int n = rand()%108;
        while(!strcmp(pecs[n],"--")){

            n = rand()%108;

        }
        strcpy(pecs_j[k],pecs[n]);
        strcpy(pecs[n],"--");

    }
}
    return SUCESSO;

}

int dev_pecs(char *pec, char **pecs_j, char **pecs){

    int i = 0;
    while(strcmp(pec,pecs_j[i]) != 0 && i < 6){
        i++;
    }

    if(strcmp(pec,pecs_j[i]) != 0){
        return N_enc;
    }

    int j = 0;
    while(strcmp("--",pecs[j]) != 0 && j < 108){
        j++;
    }    
    
    if(strcmp("--",pecs[j]) != 0){
        return ERRO;
    }

    strcpy(pecs[j],pecs_j[i]);
    
    strcpy(pecs_j[i],"--");
    
    rep_pecs(pecs_j,pecs);

    return SUCESSO;
}

int ops(char *pec,int *x, int *y){

    char op[100];

    fgets(op,100,stdin);

    if(strncmp(op,"trocar",6) == 0){
        printf("trocar *******\n");        
    }else if(strncmp(op,"jogar",5) == 0){
        printf("jogar ********\n");
    }else if(strncmp(op,"passar",5) == 0){
        printf("passar *******\n");
    }else{
        printf("inváldio\n");
        return ERRO;
    }

    return SUCESSO;

}
