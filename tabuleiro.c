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
    tab_t->c_X = 0;
    tab_t->c_Y = 0;

    for(int k = 0; k < tab_t->tab_C; k++){

        for(int l = 0; l < tab_t->tab_H;l++){

            tab_t->tab[k][l] = "|-|";
        
        }

    }

    tab_t->lin_L = 4;
    tab_t->col_L = 20;

    tab_t->tab[tab_t->lin_L][tab_t->col_L] = "|X|";

    return SUCESSO;

}

int exp_tab(tab_def *tab_t, int lin_L, int col_L){
   
    int dist_dir = tab_t->tab_C - col_L - 1;
    int dist_esq = col_L;
    int dist_top = lin_L;
    int dist_bot = tab_t->tab_H - lin_L - 1;

    
    if(dist_dir <= qwk_len){
        
        int tmp = tab_t->tab_H;
    
        tab_t->tab_C += 2*qwk_len;
        char ***aux;
        aux = tab_t->tab;
        if(aux == NULL){
            
            return ERRO;

        }
        
    for(int i = tmp-1;i < tab_t->tab_H;i++){

        aux[i] = (char **) malloc(sizeof(char**)*tab_t->tab_C);

        if(aux[i] == NULL){
                return ERRO;
        }
    }

        tab_t->tab = aux;
        
        printf("teste\n");

        for(int k = 0;k < tab_t->tab_H; k++){

            for(int l = tmp; l < tab_t->tab_C;l++){

                tab_t->tab[k][l] = "|-|";
        
             }

         }

        for(int k = 0;k < tab_t->tab_H; k++){

            for(int l = 0; l < tab_t->tab_C;l++){

               printf("teste:%s, K:%d, L:%d \n", tab_t->tab[k][l],k,l);
        
             }

         }         

            tab_t->tab[24][0] = "|D|";
        
        printf("dist_dir: %d\n",dist_dir);
    }

    if(dist_esq <= qwk_len){
    
        printf("dist_esq: %d\n",dist_esq);

    }

    if(dist_top <= qwk_len){
    
        printf("dist_top: %d\n",dist_top);

    }

    if(dist_bot <= qwk_len){
    
        int tmp = tab_t->tab_H;
    
        tab_t->tab_H += 2*qwk_len;
        char ***aux;
        aux = (char ***) malloc(sizeof(char***)*tab_t->tab_H);
        if(aux == NULL){
            
            return ERRO;

        }
        
        for(int i = 0;i < tmp;i++){

            aux[i] = tab_t->tab[i];
            
        }



        for(int i = tmp;i < tab_t->tab_H;i++){

          aux[i] = (char **) malloc(sizeof(char**)*tab_t->tab_C);

          if(aux[i] == NULL){
            return ERRO;
          }
        }
        
       // for(int i = 0;i < tmp
        tab_t->tab = aux;
        
        for(int k = tmp;k < tab_t->tab_H; k++){

            for(int l = 0; l < tab_t->tab_C;l++){

                tab_t->tab[k][l] = "|-|";
        
             }

         }

         printf("dist_bot: %d\n",dist_bot);

    }
    
    return SUCESSO;
}

void print_tab(tab_def *tab_t, char ***tab){
    
    for(int k = 0; k < tab_t->tab_H; k++){

        for(int l = 0; l < tab_t->tab_C;l++){

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
