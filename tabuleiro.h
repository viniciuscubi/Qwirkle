

#define tab_dim 6 //Dimensão base do tabuleiro
#define str_siz 3

#define ERRO 0 
#define SUCESSO 1 

typedef struct tab_t {

    char ***tab;
    
    int i;
    int j;

    int tab_C;
    int tab_H;

    int lin_L; //Ultima linha jogada
    int col_L; //Ultima coluna jogada

}tab_def;

int criar_tab(tab_def *tab_t); //Cria o tabuleiro

int exp_tab(tab_def *tab_t, char ***tab); //Expandir tabuleiro

void print_tab(tab_def *tab_t, char ***tab);//Imprime o tabuleiro no terminal

void del_tab(tab_def *tab_t, char ***tab);//Deleta a tabela do jogo
