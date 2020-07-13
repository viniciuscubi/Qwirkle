

typedef struct pec_p{

    char **num_tip; //Numeros de referencia para a criação de peças
    char **let_tip; //Letras de referencia para criação das peças
    char **pecs;

}pec_def;

typedef struct jog_j{

    char *nome;
    int pontos;
    char **pecs;

}jog_def;

void get_int(int *num);

int crt_pec(pec_def *pec_p); //Cria as peças do jogo

int crt_jog(jog_def *jog_j, char **pecs); //Cria os jogadores

int rep_pecs(char **pecs_j, char **pecs); //Repassa as peças ao jogador

int dev_pecs(char *pec, char **pecs_j, char **pecs); //Devolve as peças do jogador ao montante e retorna novas peças ao jogador

int ops(char ***tab, char **pecs_j, char **pecs, int *lin_l, int *col_l); //Le a operação escrita pelo jogador e retorna um valor relativo a isso

int jog_valida(int x, int y,char *pec,char ***tab);//Função para verificar a validade da jogada

int jogar_jog(int x, int y, char *pec, char **pecs_j, char ***tab, int *lin_l, int *col_l);

