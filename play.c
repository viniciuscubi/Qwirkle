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

    char *nome;
    int pontos  = 0;
    char **pecs_j;
    
    nome = (char *) malloc(sizeof(char*)*100);

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

int ops(char ***tab,char **pecs_j, char **pecs,int *lin_l, int *col_l){

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

        return PASSAR;

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

            if(od == 2 && flag3 == 0 && op[i] >= '0' && op[i] <= '9'){
                
                if(flag1 == 0){

                    num1 = (op[i] - '0')*10;

                    if(op[i-1] == '-'){
                        num1 = num1*(-1);
                    }

                }else{
                    
                    if(op[i-2] == '-'){
                        num1 -= (op[i]-'0');
                    }else{

                        num1 += (op[i] - '0');

                    }

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

            if(od == 3 && flag3 == 0 && op[i] >= '0' && op[i] <= '9'){                
                if(flag2 == 0){
                    

                    num2 = (op[i] - '0')*10;

                    if(op[i-1] == '-'){

                        num2 = num2*(-1);

                    }

                    if(op[i+1] == '\0' || op[i+1] == '\n'){
                        
                        num2 = num2/10;
                        flag3 = 1;

                    }

                }else{
                    
                    if(op[i-2] == '-'){
                        num2 -= (op[i] - '0');
                    }else{

                      num2 += (op[i] - '0');
                    }
                
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
            
            int x = num1;// ver numeros negativos
            int y = num2;
            char *pec;

            pec = (char *)malloc(sizeof(char *)*2);
            
            if(pec == NULL){

                return ERRO;

            }
            strncpy(pec,p,2);
            
            if(jog_valida(x,y,pec,tab) == ERRO){

                printf("Local inválido\n");
                return ERRO;
            }else{
                int r;
                r = jogar_jog(x,y,pec,pecs_j,tab,lin_l,col_l);

                if(r == 0){

                    printf("Peça invalida\n");
                    return ERRO;
                }
                
                rep_pecs(pecs_j,pecs);
                return SUCESSO;
            }
            
           // printf("pec: %s, x: %d, y: %d\n",pec,x,y);
            free(pec);
            return SUCESSO;


        }else{
            printf("ERRO\n");
            return ERRO;

        }
        


    }else if(strncmp(op,"passar",5) == 0){
        printf("passar *******\n");
        return PASSAR;//2 = passar
    }else{
        printf("inváldio\n");
        return ERRO;
    }

    return SUCESSO;

}

int jog_valida(int x, int y,char *pec,char ***tab){

   int lin = y + tab_dim/2 - 1;
   int col = x + tab_dim/2 - 1;
   int verL[4] = {0,0,0,0};
   int verN[4] = {0,0,0,0};
   int dir[4] = {0,0,0,0};
    
   printf("lin: %d, col %d\n",lin,col); 
   if(strcmp(tab[col][lin],"  ") != 0){
        printf("str: %s\n",tab[col][lin]);
        printf("ver1\n");
        return ERRO;
   }
   if(x == 0 && y == 0){

        return SUCESSO;
   }

   if(tab[col+1][lin][0] == pec[0]){
        verL[0] = 1;
   }
   if(tab[col-1][lin][0] == pec[0]){
        verL[1] = 1;
   }
   if(tab[col][lin+1][0] == pec[0]){
        verL[2] = 1;
   }
   if(tab[col][lin-1][0] == pec[0]){
        verL[3] = 1;
   }


   if(tab[col+1][lin][1] == pec[1]){
        verN[0] = 1;
   }
   if(tab[col-1][lin][1] == pec[1]){
        verN[1] = 1;
   }
   if(tab[col][lin+1][1] == pec[1]){
        verN[2] = 1;
   }
   if(tab[col][lin-1][1] == pec[1]){
        verN[3] = 1;
   }
    
   
   for(int i = 0; i < 4; i++){

    dir[i] = verL[i]^verN[i];

   }
   for(int i = 0; i < 4 ; i++){
        
        printf("L: %d, N: %d\n",verL[i],verN[i]);

        if(verL[i] == 1 && verN[i] == 1){
            
           printf("ver2\n");
            return ERRO;
        }

   }

   if(dir[0] == 1){
    int i = 1;
    while(strcmp(tab[col+i][lin],"  ") != 0){

        if(strcmp(tab[col+i][lin],pec) == 0){
            
            printf("ver3\n");
            return ERRO;

        }
        i++;
    }
    if( i > 5){
        
        printf("ver4\n");
        return ERRO;
    }

   }
   if(dir[1] == 1){

    int i = 1;
    while(strcmp(tab[col-i][lin],"  ") != 0){

        if(strcmp(tab[col-i][lin],pec) == 0){
            printf("ver5\n");
            return ERRO;

        }
        i++;
    }
    if( i > 5){
        printf("ver6\n");
        return ERRO;
    }



   }
   if(dir[2] == 1){


    int i = 1;
    while(strcmp(tab[col][lin+i],"  ") != 0){

        if(strcmp(tab[col][lin+i],pec) == 0){
            printf("ver7\n");
            return ERRO;

        }
        i++;
    }
    if( i > 5){

        printf("ver8\n");
        return ERRO;
    }


   }
   if(dir[3] == 1){

    int i = 1;
    while(strcmp(tab[col][lin-i],"  ") != 0){

        if(strcmp(tab[col][lin-i],pec) == 0){
            printf("ver9\n");
            return ERRO;

        }
        i++;
    }
    if( i > 5){
        printf("ver10\n");
        return ERRO;
    }



   }
    int tmp = 0;
    for(int i = 0; i < 4;i++){
        
        if(verL[i] == 1 || verN[i] == 1){
            
            tmp = 1;
        }
    }
    if(tmp == 1){

        return SUCESSO;
    }else{

        return ERRO;

    }
}

int jogar_jog(int x, int y, char *pec, char **pecs_j, char ***tab,int *lin_l, int *col_l){
    
    int flag = 0;
    int i = 0;
    int lin = y + tab_dim/2 -1;
    int col =  x + tab_dim/2 -1;
    char *str;

    str = (char *)malloc(sizeof(char *)*2);
    if(str == NULL){

        return ERRO;
    }

    //printf("jogar col: %d , lin %d\n",col,lin);
    for(i = 0; i < 6;  i++){

        if(strcmp(pec, pecs_j[i]) == 0){

           // printf("ver1\n");
            flag  = 1;
            break;    

        }
        
    }
    
    if(flag == 1){
        //printf("ver2\n");
        strcpy(str,pecs_j[i]);
        tab[lin][col] = str;
        //printf("ver3\n");
        strcpy(pecs_j[i],"--");
        *lin_l = lin;
        *col_l = col;

    }else{

        return ERRO;
    }




}
void get_int(int *num){


    int flag = 0;
    char str[100];

    fgets(str,100,stdin);

    *num = atoi(str);

    int i = 0;


}
