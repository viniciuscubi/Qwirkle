#include<stdio.h>
#include"tabuleiro.h"

int main(int argc, char *argv[]){

tab_def tab_t;

tab_t.tab = NULL;

tab_t.lin_L = 0;
tab_t.col_L = 0;

criar_tab(&tab_t);
printf("\n\n\n");
exp_tab(&tab_t, tab_t.lin_L, tab_t.col_L);

jogar(&tab_t,1,0);

printf("\n\n\n");
exp_tab(&tab_t, tab_t.lin_L, tab_t.col_L);

jogar(&tab_t,2,0);

printf("\n\n\n");
exp_tab(&tab_t, tab_t.lin_L, tab_t.col_L);

jogar(&tab_t,3,0);

printf("\n\n\n");
exp_tab(&tab_t, tab_t.lin_L, tab_t.col_L);

jogar(&tab_t,-1,0);

printf("\n\n\n");
exp_tab(&tab_t, tab_t.lin_L, tab_t.col_L);

jogar(&tab_t,-2,0);

printf("\n\n\n");
exp_tab(&tab_t, tab_t.lin_L, tab_t.col_L);

jogar(&tab_t,0,1);

printf("\n\n\n");
exp_tab(&tab_t, tab_t.lin_L, tab_t.col_L);

jogar(&tab_t,0,-1);

printf("\n\n\n");
exp_tab(&tab_t, tab_t.lin_L, tab_t.col_L);


jogar(&tab_t,-1,-1);

printf("\n\n\n");
exp_tab(&tab_t, tab_t.lin_L, tab_t.col_L);


del_tab(&tab_t, tab_t.tab);


}

