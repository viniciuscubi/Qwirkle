#include<stdio.h>
#include"tabuleiro.h"

int main(int argc, char *argv[]){


tab_def tab_t;
pec_def pec_p;

int num_j = 0;
printf("Insira o número de jogadores\n");

get_int(&num_j);
while(num_j <= 0){
    printf("Número de jogadores inválido!!!\n");
    get_int(&num_j);
}

jog_def jog_j[num_j];
crt_pec(&pec_p);
criar_tab(&tab_t);

for(int k = 0; k < num_j; k++){

    printf("Jogador: #%d - ",k+1);
    crt_jog(&jog_j[k],pec_p.pecs);
    printf("Suas peças são:\n");
    for(int j = 0;j < 6;j++){
        printf(" %s ",jog_j[k].pecs[j]);
    }
    printf("\n");
}

int j = 0;
while(1){
    
    printf("\n");
    printf("Jogo Qwirkle:\n");
    printf("========================\n");
    exp_tab(&tab_t, tab_t.lin_L, tab_t.col_L);
    printf("\n");
    
    for(int i = 0; i < num_j; i++){
        
        printf("Jogador: %s (score %d) :",jog_j[i].nome,jog_j[i].pontos);

        for(int k = 0; k < 6; k++){
            
            printf(" %s",jog_j[i].pecs[k]);
        
        }
        printf("\n");
        
    }
    printf("========================\n");
    printf("Jogada de %s\n",jog_j[j].nome);
    
    printf("Peças disponíveis:");

    for(int i = 0; i < 6; i++){

        printf(" %s",jog_j[j].pecs[i]);
    }
    printf("\n");

    int tmp = 0;
    while(tmp != 2){
        printf("Opções: Jogar P1 x y | passar | trocar P1 P2...P6\n");
        tmp = ops(tab_t.tab,jog_j[j].pecs,pec_p.pecs, &tab_t.lin_L, &tab_t.col_L);
        printf("========================\n");
        exp_tab(&tab_t, tab_t.lin_L, tab_t.col_L);
        printf("========================\n");

    }

    j++;

    if(j == num_j){

        j = 0;
    }

}

printf("\n\n\n");

for(int i = 0; i < 108; i++){
    
    if(i%36 == 0){
        printf("\n\n\n");
    }

    printf(" %s ",pec_p.pecs[i]);
    
}

printf("\n");

del_tab(&tab_t, pec_p.pecs);


}

