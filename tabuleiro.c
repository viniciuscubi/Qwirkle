#include<stdio.h>
#include<stdlib.h>
#include"tabuleiro.h"

int criar_tab(tab_def *tab_t){

    tab_t->tab = (char ***) malloc(sizeof(char***)*tab_dim);
    
    if(tab_t->tab == NULL){
        
        return ERRO;

    }
    
    for(int k = 0; k < tab_dim; k++){
        
        tab_t->tab[k] = (char **) malloc(sizeof(char**)*tab_dim);
        
        if(tab_t->tab[k] == NULL){
            
            return ERRO;

        }
    }

    tab_t->tab_C = tab_dim;
    tab_t->tab_H = tab_dim;

    return SUCESSO;

}

int exp_tab(tab_def *tab_t, char ***tab){


    
    return SUCESSO;
}

void print_tab(tab_def *tab_t, char ***tab){
    
    for(int k = 0; k < tab_t->tab_C; k++){

        for(int l = 0; l < tab_t->tab_H;l++){

            tab_t->tab[k][l] = "1TESTE1";

        }

    }

    
    for(int k = 0; k < tab_t->tab_C; k++){

        for(int l = 0; l < tab_t->tab_H;l++){

           printf("%s ", tab_t->tab[k][l]);
            
        }
        
        printf("\n");
    }

}

void del_tab(tab_def *tab_t, char ***tab){

    for(int k = 0; k < tab_t->tab_C; k++){
        
       free(tab_t->tab[k]);
        
    }

    free(tab_t->tab);
}
