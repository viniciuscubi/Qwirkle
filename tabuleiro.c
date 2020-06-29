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
   

    tab_t->tab_com = tab_dim/2;
    tab_t->tab_H = tab_dim/2;
    tab_t->prt_com = tab_dim/2 - 1;
    tab_t->prt_H = tab_dim/2 - 1;

    for(int k = 0; k < tab_dim; k++){

        for(int l = 0; l < tab_dim;l++){

            tab_t->tab[k][l] = "|-|";
        
        }

    }

    tab_t->lin_L = 53;
    tab_t->col_L = 53;

    tab_t->tab[tab_t->lin_L][tab_t->col_L] = "|X|";

    return SUCESSO;

}


int exp_tab(tab_def *tab_t, int lin_L, int col_L){
   
    int dist_dir = tab_t->tab_com - col_L - 1;
    int dist_esq = col_L - tab_t->tab_com + 1;
    int dist_top = lin_L - tab_t->tab_H + 1;
    int dist_bot = tab_t->tab_H - lin_L - 1;
    
    printf("dir: %d, esq: %d, top: %d, bot: %d\n",dist_dir,dist_esq,dist_top,dist_bot);

    if(dist_dir < 1){
    
        tab_t->tab_com += 1;

    }
    if(dist_esq < 1){

        tab_t->prt_com -= 1;

    }

    if(dist_top < 1){

        tab_t->prt_H -= 1;

    }

    if(dist_bot < 1){

        tab_t->tab_H += 1;
    
    }

    return SUCESSO;
}

void print_tab(tab_def *tab_t, char ***tab){
    
    for(int k = tab_t->prt_H; k < tab_t->tab_H; k++){

        for(int l = tab_t->prt_com; l < tab_t->tab_com ;l++){

           printf("%s ", tab_t->tab[k][l]);
            
        }
        
        printf("\n");
    }
    tab_t->lin_L = tab_t->tab_H-1;
    tab_t->col_L = tab_t->tab_com-1;
    printf("X: %d, Y:%d\n",  tab_t->lin_L,  tab_t->col_L); 
    tab_t->tab[tab_t->lin_L][tab_t->col_L] = "|X|";
}

void del_tab(tab_def *tab_t, char ***tab){

    for(int k = 0; k < tab_dim; k++){
        
       free(tab_t->tab[k]);
        
    }

    free(tab_t->tab);
}
