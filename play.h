

typedef struct pec_p{

    char **num_tip; //Numeros de referencia para a criação de peças
    char **let_tip; //Letras de referencia para criação das peças
    char **pecs;

}pec_def;

void crt_pec(pec_def *pec_p); //Cria as peças do jogo

void del_pec(pec_def *pec_p); //deleta as peças

