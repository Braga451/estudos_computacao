#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agenda{
    char nome[30];
    char endereco[100];
    char fone[10];
    long int CEP;
}AGENDA;

AGENDA array_agenda[100];
int posicao_array = 0;

void inserir(){
    if(posicao_array < 100){
        AGENDA nova_agenda;
        printf("Insira um nome: ");
        fgets(nova_agenda.nome, 30, stdin);
        printf("Insira um endereco: ");
        fgets(nova_agenda.endereco, 100, stdin);
        printf("Inisra um número: ");
        fgets(nova_agenda.fone, 10, stdin);
        printf("Insira o CEP (somente números): ");
        scanf("%ld", &nova_agenda.CEP);
        array_agenda[posicao_array] = nova_agenda;
        posicao_array++;
        setbuf(stdin, NULL);
    }
    else
        puts("Agenda cheia!");
}

void exibir_dados(char * nome){
    for(int x = 0; x < posicao_array; x++){
        if(strcmp(nome, array_agenda[x].nome) == 0){
            puts("----Dados----");
            printf("Nome: %sEndereço: %sNúmero: %sCEP: %ld\n", array_agenda[x].nome, array_agenda[x].endereco, array_agenda[x].fone, array_agenda[x].CEP);
            puts("----FIM----");
        }
    }
}

void exibir_dados_por_letra(char letra){
    for(int x = 0; x < posicao_array; x++){
        if(letra == array_agenda[x].nome[0]){
            puts("----Dados----");
            printf("Nome: %sEndereço: %sNúmero: %sCEP: %ld\n", array_agenda[x].nome, array_agenda[x].endereco, array_agenda[x].fone, array_agenda[x].CEP);
            puts("----FIM----");
        }
    }
}

void main(){
    int opcao = 0; 
    char nome[255], letra;
    while(opcao != -1){
        opcao = 0;
        strcpy(nome, "");
        puts("\n1 - Inserir na agenda\n2 - Exibir dados de uma das pessoas cadastradas (por nome)\n3 - Exibir os dados de uma lista de pessoas que iniciam com a mesma letra\n-1 - Sair");
        scanf("%d", &opcao);
        setbuf(stdin, NULL);
        switch(opcao){
            case 1:
                inserir();
                break;
            case 2:
                printf("Insira o nome da pessoa: ");
                fgets(nome, 254, stdin);
                exibir_dados(nome);
                break;
            case 3:
                printf("Insira a letra: ");
                letra = getchar();
                exibir_dados_por_letra(letra);
        }
    }
}
