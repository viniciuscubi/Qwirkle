#include<stdio.h>
#include"tabuleiro.h"

int main(int argc, char *argv[]){
int x = 0;
int y = 0;
char w[2] = "A1";

//ops(w,&x,&y);
//return 0;// apenas para teste
tab_def tab_t;
pec_def pec_p;

int num_j;
//scanf("%d",&num_j);

num_j = 4 ;
jog_def jog_j[num_j];

crt_pec(&pec_p);

criar_tab(&tab_t);

for(int k = 0; k < num_j; k++){

    printf("Jogador #%d - ",k+1);
    crt_jog(&jog_j[k],pec_p.pecs);
    printf("peças:\n");
    for(int j = 0;j < 6;j++){
        printf(" %s ",jog_j[k].pecs[j]);
    }
    printf("\n");
}

dev_pecs(jog_j[0].pecs[0],jog_j[0].pecs,pec_p.pecs);

printf("peça trocada: %s \n",jog_j[0].pecs[0]); 

printf("\n\n\n");
exp_tab(&tab_t, tab_t.lin_L, tab_t.col_L);

jogar(&tab_t,0,0);

printf("\n\n\n");
exp_tab(&tab_t, tab_t.lin_L, tab_t.col_L);

jogar(&tab_t,1,0);

printf("\n\n\n");
exp_tab(&tab_t, tab_t.lin_L, tab_t.col_L);

for(int i = 0; i < 108; i++){
    
    if(i%36 == 0){
        printf("\n\n\n");
    }

    printf(" %s ",pec_p.pecs[i]);
    
}

printf("\n");

del_tab(&tab_t, pec_p.pecs);


}

