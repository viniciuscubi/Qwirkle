#include<stdio.h>
#include"tabuleiro.h"

int main(int argc, char *argv[]){

tab_def tab_t;
pec_def pec_p;

tab_t.tab = NULL;

tab_t.lin_L = 0;
tab_t.col_L = 0;

crt_pec(&pec_p);

printf("pec: %s\n", pec_p.pecs[58]);


criar_tab(&tab_t);


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

