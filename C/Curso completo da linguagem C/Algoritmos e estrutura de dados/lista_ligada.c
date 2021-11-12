#include <stdio.h>
#include <stdlib.h>

struct ListaLigadaNo{
    void * data;
    int tipo_data; /* 1 - Int | 2 - Float */
    struct ListaLigada * proximo_no;
}typedef LISTA_LIGADA_NO;

void inicializarNo(LISTA_LIGADA_NO * no){
    no->data = NULL;
    no->proximo_no = NULL;
    no->tipo_data = NULL;
}

void inicializarLista(LISTA_LIGADA_NO * cabeca){
    int tipo_data;
    inicializarNo(cabeca);
    printf("Digite se quer inteiro(1) ou float(2): ");
    scanf("%d", &tipo_data);
    switch(tipo_data){
        case 1:
            cabeca->data = (int *) malloc(sizeof(int));
            printf("Digite o inteiro: ");
            scanf("%d", cabeca->data);
            cabeca->tipo_data = 1;
            break;
        case 2:
            cabeca->data = (float *) malloc(sizeof(float));
            printf("Digite o float: ");
            scanf("%f", cabeca->data);
            cabeca->tipo_data = 2;
            break;
        default:
            exit(1);
    }
}

void imprimeLista(LISTA_LIGADA_NO * cabeca){
    LISTA_LIGADA_NO * aux = cabeca;
    puts("-----LISTA-----");
    while(aux != NULL){
        if(aux->tipo_data == 1){
            printf("%d\n", *((int *) aux->data));
        }
        else{
            printf("%.2f\n", *((float *) aux->data));
        }
        aux = aux->proximo_no;
    }
    puts("-----FIM-----");
}

LISTA_LIGADA_NO * adicionarNo(LISTA_LIGADA_NO * cabeca, int posicao, int tipo_data){
    LISTA_LIGADA_NO * aux = cabeca, * novo_no = (LISTA_LIGADA_NO *) malloc(sizeof(LISTA_LIGADA_NO));
    int contador = 1;
    inicializarNo(novo_no);
    for(contador; contador < posicao; contador++){
        if(aux->proximo_no != NULL){
            aux = aux->proximo_no;
        }
        else{
            printf("Saindo do laço...\n");
            break;
        }
    }
    switch(tipo_data){
        case 1:
            novo_no->tipo_data = 1;
            novo_no->data = (int *) malloc(sizeof(int));
            printf("Digite o inteiro: ");
            scanf("%d", ((int *) novo_no->data));
            break;
        case 2:
            novo_no->tipo_data = 2;
            novo_no->data = (float *) malloc(sizeof(float));
            printf("Digite o float: ");
            scanf("%f", ((float *) novo_no->data));
            break;
        default:
            exit(1);
    }
    if(posicao == 0){
        printf("Colocando o no no começo da lista...\n");
        novo_no->proximo_no = cabeca;
        cabeca = novo_no;
        return cabeca;
    }
    else if(contador < posicao){
        printf("Colocando o no no final da lista...\n");
        aux->proximo_no = novo_no;
        return cabeca;
    }
    else{
        printf("Colocando o no na posicao desejada(%d)...\n", posicao);
        novo_no->proximo_no = aux->proximo_no;
        aux->proximo_no = novo_no;
        return cabeca;
    }
}

LISTA_LIGADA_NO * removerNo(LISTA_LIGADA_NO * cabeca, int posicao){
    LISTA_LIGADA_NO * aux = cabeca, * aux2;
    int contador = 1;
    for(contador; contador < posicao; contador++){
        if(aux->proximo_no != NULL){
            aux = aux->proximo_no;
        }
        else{
            printf("Saindo do laço...\n");
            break;
        }
    }
    if(contador == 1 && aux->proximo_no == NULL){
        free(cabeca);
        cabeca = (LISTA_LIGADA_NO *) malloc(sizeof(LISTA_LIGADA_NO));
        inicializarNo(cabeca);
    }
    else if(posicao == 0){
        cabeca = cabeca->proximo_no;
    }
    else if(contador <= posicao){
        aux2 = cabeca;
        while(aux2->proximo_no != aux){
            aux2 = aux2->proximo_no;
        }
        aux2->proximo_no = NULL;
    }
    else{
        aux2 = aux->proximo_no;
        aux2 = aux2->proximo_no;
        aux->proximo_no = aux2;
    }
    return cabeca;
}

void main(){
    LISTA_LIGADA_NO * lista_ligada = (LISTA_LIGADA_NO *) malloc(sizeof(LISTA_LIGADA_NO));
    int opcao = 0, posicao = 0;
    inicializarLista(lista_ligada);
    while(1){
        puts("----------");
        printf("1 - Inserir inteiro\n2 - Inserir float\n3 - Remover no\n-1 - Sair\n: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Insira a posição onde deseja inserir o no: ");
                scanf("%d", &posicao);
                lista_ligada = adicionarNo(lista_ligada, posicao, 1);
                break;
            case 2:
                printf("Insira a posição onde deseja inserir o no: ");
                scanf("%d", &posicao);
                lista_ligada = adicionarNo(lista_ligada, posicao, 2);
                break;
            case 3:
                if(lista_ligada->proximo_no != NULL){
                    printf("Insira a posição onde deseja remover o no: ");
                    scanf("%d", &posicao);
                    lista_ligada = removerNo(lista_ligada, posicao);
                }
                else{
                    printf("Não foi possível rmeover o primeiro no\n");
                }
                break;
            case -1:
                exit(0);
                break;
        }
        imprimeLista(lista_ligada);
    }
}
