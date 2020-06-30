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

    printf("t_com: %d, t_H: %d, p_com: %d, p_H %d\n",tab_t->tab_com,tab_t->tab_H,tab_t->prt_com,tab_t->prt_H);

    for(int k = 0; k < tab_dim; k++){

        for(int l = 0; l < tab_dim;l++){

            tab_t->tab[k][l] = "  ";
        
        }

    }

    tab_t->lin_L = 53;
    tab_t->col_L = 53;

    tab_t->tab[tab_t->lin_L][tab_t->col_L] = "2B";

    return SUCESSO;

}


int exp_tab(tab_def *tab_t, int lin_L, int col_L){
   
    int dist_dir = tab_t->tab_com - col_L - 1;
    int dist_esq = col_L - tab_t->prt_com;
    int dist_top = lin_L - tab_t->prt_H;
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
/*
    tab_t->tab_H = tab_dim/2 + 20;
    tab_t->tab_com = tab_dim/2 + 20;
    tab_t->prt_H = 27 + 10;
    tab_t->prt_com = 27 + 10;
    //Apenas para teste
*/
    printf("\n");
    print_tab(tab_t->tab,tab_t->prt_H, tab_t->tab_H, tab_t->prt_com, tab_t->tab_com);

    return SUCESSO;
}

void print_tab(char ***tab,int prt_H, int tab_H,int prt_com,int tab_com){
    
    printf("    ");

    for(int k = prt_com; k < tab_com; k++){

        int tmp = k-tab_dim/2+1;
        
        if(tmp < 0 && tmp >= -9){
            printf(" %d  ",tmp);
        }else if(tmp > 9){
            printf(" %d  ",tmp);
        }else if(tmp < -9){
            printf("%d  ",tmp);
        }else{
            printf("  %d  ",tmp);
        }
    }
    printf("\n");

    for(int k = prt_H; k < tab_H; k++){
        
        int tmp = k-tab_dim/2+1;
         
        if(tmp < 0 && tmp >= -9){
            printf(" %d ",tmp);
        }else if(tmp > 9){
            printf(" %d ",tmp);
        }else if(tmp < -9){
            printf("%d ",tmp);
        }else{

            printf("  %d ",tmp);

        }
 
        for(int l = prt_com; l < tab_com ;l++){
        
            if(l != tab_com-1){
                 printf(" %s |", tab[k][l]);
             }else{
                 printf(" %s  ", tab[k][l]);
             }
          
        }

         if(tmp < 0 && tmp >= -9){
            printf(" %d ",tmp);
        }else if(tmp > 9){
            printf(" %d ",tmp);
        }else if(tmp < -9){
            printf("%d ",tmp);
        }else{

            printf("  %d ",tmp);

        }

        printf("\n    ");
        for(int l = prt_com; l < tab_com && k != tab_H-1  ; l++){
            printf("-----");
        }
        printf("\n");

    }
    
    printf("    ");
    for(int k = prt_com; k < tab_com; k++){

        int tmp = k-tab_dim/2+1;
        
        if(tmp < 0 && tmp >= -9){
            printf(" %d  ",tmp);
        }else if(tmp > 9){
            printf(" %d  ",tmp);
        }else if(tmp < -9){
            printf("%d  ",tmp);
        }else{
            printf("  %d  ",tmp);
        }
    }
    printf("\n");
 
}
void jogar(tab_def *tab_t, int lin, int col){
    
    lin += tab_dim/2 - 1;
    col += tab_dim/2 - 1;
    tab_t->lin_L = lin;
    tab_t->col_L = col;
    tab_t->tab[lin][col] = "3C";

}

void del_tab(tab_def *tab_t, char ***tab){

    for(int k = 0; k < tab_dim; k++){
        
       free(tab_t->tab[k]);
        
    }

    free(tab_t->tab);
}
