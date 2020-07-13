#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tabuleiro.h"

int main(int argc, char *argv[]){


tab_def tab_t;
pec_def pec_p;

int num_j = 0;
int modo = 0;

printf("Insira o número de jogadores\n");

get_int(&num_j);
while(num_j <= 0){
    printf("Número de jogadores inválido!!!\n");
    get_int(&num_j);
}


printf("Deseja ativar o modo Cheat? digite 1 para SIM e 2 para NAO\n");
get_int(&modo);
while(modo != 1 && modo != 2){
    printf("Número invalido, insira novamente!\n");
    get_int(&modo);
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
    jog_j[k].pontos = 0;
}

int j = 0;
int end = 1;
while(end){
    
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
    int flag = 0;
    int tcol = 0;
    int tlin = 0;
    int tmp  = 0;
    while(tmp != PASSAR){
        printf("Opções: Jogar P1 x y | passar | trocar P1 P2...P6\n");
        tmp = ops(tab_t.tab,jog_j[j].pecs,pec_p.pecs, &tab_t.lin_L, &tab_t.col_L, modo);

        if(tmp == JOGADA && flag == 0){
            tcol = tab_t.col_L;
            tlin = tab_t.lin_L;

            flag  = 1;
        }

        if(tmp == PASSAR && flag == 1){

            pontos(&jog_j[j].pontos,tab_t.tab,tlin, tcol);
        }    

        printf("========================\n");
        exp_tab(&tab_t, tab_t.lin_L, tab_t.col_L);
        printf("\nJogada de %s\n",jog_j[j].nome);
        printf("========================\n");

    }
        
    j++;

    if(j == num_j){

        j = 0;
    }

    for(int k = 0; k < num_j; k++){
        int flag = 0;
        for(int l = 0; l < 6; l++){
            
            if(strcmp(jog_j[k].pecs[l],"--") != 0){
                
                flag = 1;
            }
        }
        if(flag == 0){

            jog_j[k].pontos += 6;
            end = 0;
            break;
        }
    
    }

}

int jogV = 0;
int i = 0;
int ptmax = 0;

while(i < num_j){

    if(jog_j[i].pontos > ptmax){

        jogV = i;
        ptmax = jog_j[i].pontos;

    }


}

printf("=====================================================\n");
printf("==========================FIM========================\n");
printf("=====================================================\n\n\n");
printf("O GANHADOR É: %s COM %d PONTOS\n",jog_j[jogV].nome,jog_j[jogV].pontos);
printf("\n\n=====================================================\n");

printf("\n");

del_tab(&tab_t, pec_p.pecs);


}

