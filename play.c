#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "tabuleiro.h"
#include "play.h"

#define tips 6 //Numero de tipos de cada classe das peças
#define t_pecs 108 //Numero total de peças

void crt_pec(pec_def *pec_p){

    char *let[tips] = {"A","B","C","D","E","F"};
    char *num[tips] = {"1","2","3","4","5","6"};
    char *pecs[108];

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

                pecs[ctn] = (char *) str_L;
                ctn++;
            }

        }
    }

    for(int i = 0; i < t_pecs; i++){

        printf("peça: %s\n",pecs[i]);
    
    }
    
}
