#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct pilha{
    int * pilha;
    int topo, tamanho_pilha;
}typedef PILHA;


void exibirPilha(PILHA * pilha){
    for(int x = (pilha->tamanho_pilha) - 1; x >= 0; x--){
        printf("%d\n", pilha->pilha[x]);
    }
}


bool pilhaVazia(PILHA * pilha){
    if(pilha->topo == -1)
        return true;
    else
        return false;
}


void pilhaPush(PILHA * pilha){
    if(pilha->topo < pilha->tamanho_pilha - 1){
        (pilha->topo)++;
        printf("Digite o elemento a ser inserido: ");
        scanf("%d", &pilha->pilha[pilha->topo]);
    }
    else{
        printf("A pilha está cheia!\n");
    }
}


void pilhaPop(PILHA * pilha){
    if(pilhaVazia(pilha) == false){
        printf("O elemento removido foi: %d\n", pilha->pilha[pilha->topo]);
        pilha->pilha[pilha->topo] = 0;
        (pilha->topo)--;
    }
    else{
        printf("A pilha está vazia!\n");
    }
}


void pilhaConstrutor(PILHA * pilha){
    printf("Insira o tamanho da pilha: ");
    scanf("%d", &pilha->tamanho_pilha);
    pilha->topo = -1;
    pilha->pilha = (int * ) malloc(pilha->tamanho_pilha * sizeof(int));
}


void main(){
    PILHA pilha;
    int opcao;
    pilhaConstrutor(&pilha);
    while(opcao != -1){
        opcao = 0;
        printf("1 - Inserir um elemento na pilha\n2 - Remover o ultimo elemento da pilha\n3 - Verificar se a pilha está vazia\n4 - Exibir pilha\n-1 - Sair\n: ");
        scanf("%d", &opcao);
        if(opcao == 1)
            pilhaPush(&pilha);
        if(opcao == 2)
            pilhaPop(&pilha);
        if(opcao == 3){
            if(pilhaVazia(&pilha) == true)
                printf("Pilha está vazia!");
            else
                printf("Pilha não está vazia!");
            puts("");
        }
        if(opcao == 4)
            exibirPilha(&pilha);
    }
    free(pilha.pilha);
}
