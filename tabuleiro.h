
#include "play.h"
#define tab_dim 108 //Dimensão base do tabuleiro
#define qwk_len 6

#define ERRO 0 
#define SUCESSO 1 

typedef struct tab_t {

    char ***tab;
    
    int prt_com; //Correção no print no comprimento
    int prt_H; //Correção no print na altura
    

    int tab_com;//Comprimento do tabuleiro
    int tab_H;//ALtura do tabuleiro

    int lin_L; //Ultima linha jogada
    int col_L; //Ultima coluna jogada

}tab_def;

int criar_tab(tab_def *tab_t); //Cria o tabuleiro

int exp_tab(tab_def *tab_t, int lin_L, int col_L); //Expandir tabuleiro

void print_tab(char ***tab, int prt_H, int tab_H, int prt_com, int tab_com);//Imprime o tabuleiro no terminal

void del_tab(tab_def *tab_t, char **pecs);//Deleta a tabela do jogo

void jogar(tab_def *tab_t, int lin, int col); //função provisória

