

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


int crt_pec(pec_def *pec_p); //Cria as peças do jogo

int crt_jog(jog_def *jog_j, char **pecs); //Cria os jogadores

int rep_pecs(char **pecs_j, char **pecs); //Repassa as peças ao jogador

int dev_pecs(char *pec, char **pecs_j, char **pecs); //Devolve as peças do jogador ao montante e retorna novas peças ao jogador

int ops(char *pec,int *x,int *y, char **pecs_j, char **pecs); //Le a operação escrita pelo jogador e retorna um valor relativo a isso
