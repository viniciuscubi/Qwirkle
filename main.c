#include<stdio.h>
#include"tabuleiro.h"

int main(int argc, char *argv[]){

tab_def tab_t;

tab_t.tab = NULL;

tab_t.lin_L = 0;
tab_t.col_L = 0;

criar_tab(&tab_t);
print_tab(&tab_t, tab_t.tab);
exp_tab(&tab_t, tab_t.lin_L, tab_t.col_L);
printf("\n\n\n");
print_tab(&tab_t, tab_t.tab);
del_tab(&tab_t, tab_t.tab);


}

