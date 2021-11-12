#include <stdio.h>
#include <stdlib.h>


void exibir_valores(int * fila, int tamanho){
    for(int x = 0; x < tamanho; x++){
        if(x < tamanho - 1){
            printf("%d - ", fila[x]);
        }
        else{
            printf("%d", fila[x]);
        }
    }
    puts("");
}


void enfileirar(int **fila, int * tras, int valor, int tamanho_fila){
    if(*tras  < tamanho_fila - 1){
        *tras += 1;
        (*fila)[*tras] = valor;
    }
    else{
        printf("Fila cheia!\n");
    }
}


void desinfilerar(int ** fila, int * tras, int * frente, int tamanho_fila){
    if(*frente > *tras){
        printf("Fila vazia!\n");
        *tras = -1;  // Essa foi a melhor forma que eu consegui pensar para resetar a posição do elemento a ser inserido, e assim, poder inserir mais elementos na fila ápos desinfilerar todos.
                     // O problema é que, em tese, para conseguir resetar a fila é necessario tentar desinfilerar ela enquanto vazia.
        *frente = 0;
    }
    else{
        printf("Valor removido: %d\n", (*fila)[*frente]);
        (*fila)[*frente] = 0;
        *frente += 1;
    }
}


void main(){
    int tamanho_fila, tras = -1, frente = 0, valor_a_ser_inserido, qtd_valores_a_inserir;
    int * fila;
    printf("Insira o tamanho da fila: ");
    scanf("%d", &tamanho_fila);
    fila = (int * ) malloc(tamanho_fila * sizeof(int));
    printf("Deseja inserir quantos valores?: ");
    scanf("%d", &qtd_valores_a_inserir);
    for(int x = 0; x < qtd_valores_a_inserir; x++){
        printf("Digite o valor a ser inserido: ");
        scanf("%d", &valor_a_ser_inserido);
        enfileirar(&fila, &tras, valor_a_ser_inserido, tamanho_fila);
    }
    exibir_valores(fila, tamanho_fila);
}
