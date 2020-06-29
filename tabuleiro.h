

#define tab_dim 25 //Dimensão base do tabuleiro
#define qwk_len 6

#define ERRO 0 
#define SUCESSO 1 

typedef struct tab_t {

    char ***tab;
    
    int c_X; //Correção na Coordenada X
    int c_Y; //Correção na Coordenada Y

    int tab_C;
    int tab_H;

    int lin_L; //Ultima linha jogada
    int col_L; //Ultima coluna jogada

}tab_def;

int criar_tab(tab_def *tab_t); //Cria o tabuleiro

int exp_tab(tab_def *tab_t, int lin_L, int col_L); //Expandir tabuleiro

void print_tab(tab_def *tab_t, char ***tab);//Imprime o tabuleiro no terminal

void del_tab(tab_def *tab_t, char ***tab);//Deleta a tabela do jogo
