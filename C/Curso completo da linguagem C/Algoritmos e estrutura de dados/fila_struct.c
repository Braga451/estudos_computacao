#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct FILA{
    int * array, anterior, sucessor, tamanho;
}FILA;


void construtorFila(FILA * fila){
    printf("Digite o tamanho da fila: ");
    scanf("%d", &fila->tamanho);
    fila->array = (int *) malloc(fila->tamanho * sizeof(int));
    fila->anterior = -1;
    fila->sucessor = 0;
    puts("");
}


void resetarPosicaoFila(FILA * fila){
    fila->anterior = -1;
    fila->sucessor = 0;
}


bool filaEstaCheia(FILA * fila){
    if(fila->anterior < (fila->tamanho) - 1)
        return false;
    return true;
}


bool filaEstaVazia(FILA * fila){
    if(fila->sucessor > fila->anterior)
        return true;
    return false;
}


void inserirElemento(FILA * fila){
    if(filaEstaCheia(fila))
        printf("Fila cheia!\n");
    else{
        (fila->anterior)++;
        printf("Digite o elemento a ser inserido: ");
        scanf("%d", &fila->array[fila->anterior]);
        puts("");
    }
}


void removerElemento(FILA * fila){
    if(filaEstaVazia(fila)){
        printf("Fila vazia!\n");
        return;
    }
    else{
        printf("Elemento removido: %d\n", fila->array[fila->sucessor]);
        fila->array[fila->sucessor] = 0;
        (fila->sucessor)++;
    }
}


void exibirFila(FILA * fila){
    for(int x = 0; x < (fila->tamanho); x++){
        printf("%d\n", fila->array[x]);
    }
    puts("");
}

void main(){
    FILA fila;
    int opcao = 0;
    construtorFila(&fila);
    while(opcao != -1){
        opcao = 0;
        printf("---Opcoes---\n1 - Inserir elemento\n2 - Remover elemento\n3 - Exibir fila\n4 - Resetar posições da fila\n-1 - Sair\n:");
        scanf("%d", &opcao);
        puts("----------");
        puts("");
        switch(opcao){
            case 1:
                inserirElemento(&fila);
                break;
            case 2:
                removerElemento(&fila);
                break;
            case 3:
                exibirFila(&fila);
                break;
            case 4:
                resetarPosicaoFila(&fila);
                break;
        }
    }
}
