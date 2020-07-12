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

    while(i < 6 && strcmp(pec,pecs_j[i]) != 0){
        i++;
    }

    if(i == 6){
        return ERRO;
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

int ops(char *pec,int *x, int *y,char **pecs_j, char **pecs){

    char op[100];

    fgets(op,100,stdin);

    if(strncmp(op,"trocar",6) == 0){

        printf("trocar\n");

        char **tmp = (char **) malloc(sizeof(char **)*6);

        for(int m = 0; m <6; m++){
            
            tmp[m] = (char *) malloc(sizeof(char *)*2);

        }

        int i = 6;
        int j = 0;
        int k = 0;
        while(op[i] != '\0' && j < 6){ //Pega as peças que o jogador pediu para serem trocadas
            
            if(op[i] != ' ' && op[i] != '\n'){

                tmp[j][k] = op[i];
                
                if(k == 1){
                    k = 0;
                    j++;
                }else{
                    k++;
                }
            }
            i++;
        }
        
        for(int m = 0; m < j; m++){
           int e = 1;
           e =  dev_pecs(tmp[m],pecs_j,pecs);
           if(e == ERRO){
                
                printf("Peça: %s não localizada ou não válida\n",tmp[m]);
           }
        }

        
        for(int m = 0; m < 6; m++){
            free(tmp[m]);
        }
        free(tmp);

        return SUCESSO;

    }else if(strncmp(op,"jogar",5) == 0){
        printf("jogar\n");
        
        char p[2];
        int  num1;
        int  num2;

        int i = 5;
        int od = 0; //numero da ordem
        int j = 0;
        int flag1 = 0;
        int flag2 = 0;
        int flag3 = 0;

        while(op[i] != '\0' && op[i] != '\n' && od < 4){
            
            flag3 = 0;

            if(od == 0 && op[i] >= 'A' && op[i] <= 'F'){
                p[0] = op[i];
                flag3 = 1;


            }

            if(od == 1 && op[i] >= '1' && op[i] <= '6'){
                p[1] = op[i];
                flag3 = 1;
                
            }
            

            if(od == 2 && flag1 == 1 && op[i] == ' '){
                num1 = num1/10;
                flag3 = 1;

            }

            if(od == 2 && flag3 == 0 && op[i] >= '1' && op[i] <= '9'){
                
                if(flag1 == 0){

                    num1 = (op[i] - '0')*10;

                }else{

                    num1 += (op[i]-'0');

                }

                if(flag1 ==  1){

                    flag3 = 1;

                }
                flag1 = 1;
                
            
            }

            if(od == 3 && flag2 == 1 && op[i] == ' '){
                num2 = num2/10;
                flag3 = 1;

            }

            if(od == 3 && flag3 == 0 && op[i] >= '1' && op[i] <= '9'){                
                if(flag2 == 0){

                    num2 = (op[i] - '0')*10;

                    if(op[i+1] == '\0' || op[i+1] == '\n'){
                        
                        num2 = num2/10;
                        flag3 = 1;

                    }

                }else{

                    num2 += (op[i] - '0');
                
                }

                if(flag2 == 1){

                    flag3  = 1;
                }
                flag2 = 1;
                

            }
            i++;
            if(flag3 == 1 || op[i] == '\0'){
                j = 0;
                od++;
            }
        }
        if(od == 4){

            *x = num1;
            *y = num2;
            strncpy(pec,p,2);
            
            printf("pec: %s, x: %d, y: %d\n",pec,*x,*y);
            return SUCESSO;


        }else{
            printf("ERRO\n");
            return ERRO;

        }
        


    }else if(strncmp(op,"passar",5) == 0){
        printf("passar *******\n");
    }else{
        printf("inváldio\n");
        return ERRO;
    }

    return SUCESSO;

}
