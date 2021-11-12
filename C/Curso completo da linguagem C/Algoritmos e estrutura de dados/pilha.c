#include <stdlib.h>
#include <stdio.h>

void exibirPilha(int * pilha, int tamanho){
    for(int x = tamanho - 1; x >= 0; x--){
        printf("%d\n", pilha[x]);
    }
}

void pushPilha(int ** pilha, int * topo, int tamanho, int valor_a_ser_inserido){
    if(*topo < tamanho - 1){
        *topo += 1;  //Também não consegui descobrir exatamente o porquê de *topo++ neste caso retornar 10 (aparentemente tem algo haver com a ordem de procedencia dos operadores).
        (*pilha)[*topo] = valor_a_ser_inserido; //Leia-se: Conteudo apontado por ponteiro de ponteiro (ou seja, o nosso ponteiro original) recebe no topo o valor a ser inserido.
                                                //Esse é um comportamento curioso em C, por algum motivo, para alterar o conteudo de um array por meio de uma função, é necessario passar o endereço de memoria desse array, e não para onde ele esta apontando.
 }                                              //Não consegui descobrir exatamente o porquê disto acontecer.
    else{
        puts("Pilha cheia!");
    }
}

void popPilha(int ** pilha, int * topo){
    if((*pilha)[*topo] == -1){
        printf("A pilha já esta vazia!");
    }
    else{
        printf("Valor removido: %d\n", (* pilha)[*topo]);
        (* pilha)[*topo] = 0;
        *topo -= 1;
    }
}

void main(){
    int * pilha;
    int topo = -1, tamanho, valor_a_ser_inserido;
    printf("Insira o tamanho da pilha: ");
    scanf("%d", &tamanho);
    pilha = (int *) malloc(tamanho * sizeof(int));
    for(int x = 0; x < tamanho; x++){
        printf("Insira o valor a ser inserido na pilha: ");
        scanf("%d", &valor_a_ser_inserido);
        pushPilha(&pilha, &topo, tamanho, valor_a_ser_inserido);
    }
    exibirPilha(pilha, tamanho);
    popPilha(&pilha, &topo);
    exibirPilha(pilha, tamanho);
    pushPilha(&pilha, &topo, tamanho, 16);
    exibirPilha(pilha, tamanho);
}
