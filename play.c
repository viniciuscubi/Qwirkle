#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "tabuleiro.h"

#define tips 6 //Numero de tipos de cada classe das peças
#define t_pecs 108 //Numero total de peças

void crt_pec(pec_def *pec_p){

    char *let[tips] = {"A","B","C","D","E","F"};
    char *num[tips] = {"1","2","3","4","5","6"};
    char **pecs;
    
    pecs = (char **) malloc(sizeof(char **)*108);

    for(int i = 0; i < 108;i++){

        pecs[i] = (char *) malloc(sizeof(char *)*2);

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
}

