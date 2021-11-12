#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 0 = O | 1 = X */

void limparTabela(int ** tabela){
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            tabela[x][y] = -1;
        }
    }
}

void printTabela(int ** tabela){
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            if(tabela[x][y] == 0){
                printf(" O ");
            }
            else if(tabela[x][y] == 1){
                printf(" X ");
            }
            else{
                printf(" - ");
            }
        }
        printf("\n");
    }   
}

int verificaTabela(int ** tabela){
    /*Tipos de retorno da função:
        0 = circulo venceu
        1 = x venceu
        -1 = velha
        2 = jogo continua*/
    int testarLinhasColunas[3];
    bool deu_velha = true;
    /*Testa linhas:*/
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            testarLinhasColunas[y] = tabela[x][y];    
        }
        if(testarLinhasColunas[0] != -1 && testarLinhasColunas[0] == testarLinhasColunas[1] && testarLinhasColunas[1] == testarLinhasColunas[2]){
            return testarLinhasColunas[0];
        }
    }
    /*Testa colunas*/
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            testarLinhasColunas[x] = tabela[x][y];
        }
        if(testarLinhasColunas[0] != -1 && testarLinhasColunas[0] == testarLinhasColunas[1] && testarLinhasColunas[1] == testarLinhasColunas[2]){
            return testarLinhasColunas[0];
        }
    }
    /*Testa as diagonais*/
    if(tabela[1][1] != -1 && ((tabela[0][0] == tabela[1][1] && tabela[1][1] == tabela[2][2])   || (tabela[2][0] == tabela[1][1] && tabela[1][1] == tabela[0][2]))){
        return tabela[1][1];
    }
    /*Testa se deu velha*/
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            if(tabela[x][y] == -1){
                deu_velha = false;
                break;
            }
        }
        if(!deu_velha){
            break;
        }
    }
    if(deu_velha){
        return -1;
    }
    return 2;
}

void jogo(int ** tabela){
    int peca = 0, posicoes[9], posicao_escolhida, resultado_verificao, numero_de_jogadas = 0;
    for(int x = 0; x < 9; x++){
        posicoes[x] = x + 1;
    }
    while(1){
        if(numero_de_jogadas == 0){
            resultado_verificao = 2;
        }
        else{
            resultado_verificao = verificaTabela(tabela);
        }
        if(resultado_verificao == 0){
            printf("Circulo venceu!\n");
            break;
        }
        else if(resultado_verificao == 1){
            printf("X venceu!\n");
            break;
        }
        else if(resultado_verificao == -1){
            printf("Deu velha!\n");
            break;
        }
        else{
            printTabela(tabela);
            printf("Posições disponiveis: ");
            for(int x = 0; x < 9; x++){
                if(posicoes[x] != -1){
                    printf("%d ", posicoes[x]);
                }
            }
            printf("\n");
            if(peca == 0){
                printf("Vez de O\n");
            }
            else{
                printf("Vez de X\n");
            }
            printf("Digite a posição a ser escolhida: ");
            scanf("%d", &posicao_escolhida);
            fflush(stdin);
            printf("\n");
            if(posicao_escolhida <= 0 || posicao_escolhida > 9 || posicoes[posicao_escolhida - 1] == -1){
                printf("Posição invalida! Perdeu a vez\n");
            }
            else{
                posicoes[posicao_escolhida - 1] = -1;
                switch(posicao_escolhida){
                    case 1:
                        tabela[0][0] = peca;
                        break;
                    case 2:
                        tabela[0][1] = peca;
                        break;
                    case 3:
                        tabela[0][2] = peca;
                        break;
                    case 4:
                        tabela[1][0] = peca;
                        break;
                    case 5:
                        tabela[1][1] = peca;
                        break;
                    case 6:
                        tabela[1][2] = peca;
                        break;
                    case 7:
                        tabela[2][0] = peca;
                        break;
                    case 8:
                        tabela[2][1] = peca;
                        break;
                    case 9:
                        tabela[2][2] = peca;
                        break;
                }
            }
            if(peca == 0){
                peca++;
            }
            else{
                peca--;
            }
            numero_de_jogadas++;
        }
    }
}

void main(){
    int ** tabela = (int **) malloc(3 * (sizeof(int *))), opcao;
    for(int x = 0; x < 3; x++){
        tabela[x] = (int *) malloc(sizeof(int));
    }
    while(opcao != -1){
        opcao = 0;
        limparTabela(tabela);
        printf("Digite 1 para jogar e -1 para sair: ");
        scanf("%d", &opcao);
        system("cls");
        fflush(stdin);
        printf("\n");
        if(opcao == 1){
            jogo(tabela);
            printTabela(tabela);
        }
    }
	system("pause");
}