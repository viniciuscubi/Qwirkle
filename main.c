#include<stdio.h>
#include"tabuleiro.h"

int main(int argc, char *argv[]){

tab_def tab_t;

tab_t.tab = NULL;

criar_tab(&tab_t);
print_tab(&tab_t, tab_t.tab);
del_tab(&tab_t, tab_t.tab);


}

