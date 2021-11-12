#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

void jogo(char * palavra, int tamanho_palavra){
    int chances = 10, posicao_letras_ja_digitadas = 0;
    char * mascara = (char *) malloc(tamanho_palavra * sizeof(char)), letra, letras_ja_digitadas[250];
    bool letra_foi_encontrada = false, letra_ja_digitada = false;
    for(int x = 0; x < tamanho_palavra - 1; x++){
        if(palavra[x] != ' '){
            mascara[x] = '_';
        }
        else{
            mascara[x] = ' ';
        }
    }
    for(int x = 0; x < 250; x++){
        letras_ja_digitadas[x] = '\0';
    }
    mascara[tamanho_palavra] = '\0';
    while(chances > 0){
        letra_foi_encontrada = false;
        letra_ja_digitada = false;
        printf("Palavra: %s\n", mascara);
        if(strcmp(mascara, palavra) == 0){
            printf("Você venceu!\n");
            break;
        }
        printf("Chances: %d\n", chances);
        printf("Letras já digitadas: ");
        for(int x = 0; x < 250; x++){
            if(letras_ja_digitadas[x] != '\0'){
                printf("%c ", letras_ja_digitadas[x]);
            }
        }
        printf("\n");
        printf("> ");
        scanf("%c", &letra);    
        fflush(stdin);
        for(int x = 0; x < 250; x++){
            if(letras_ja_digitadas[x] == letra){
                letra_ja_digitada = true;
            }
        }
        if(letra_ja_digitada){
            printf("Letra %c já foi digitada!\n", letra);
        }
        else{
            letras_ja_digitadas[posicao_letras_ja_digitadas] = letra;
            posicao_letras_ja_digitadas++;
            for(int x = 0; x < tamanho_palavra; x++){
                if(letra == palavra[x]){
                    mascara[x] = letra;
                    letra_foi_encontrada = true;
                }
            }
        }
        if(!letra_foi_encontrada){
            chances--;
        }
    }
    if(chances == 0){
        printf("Você perdeu!\n");
    }
    free(mascara);
    return;
}

void main(){
    setlocale(LC_ALL, "Portuguese");
    int opcao = 0, tamanho_palavra;
    char * palavra = NULL;
    while(opcao != -1){
        opcao = 0;
        tamanho_palavra = 255;
        printf("Para jogar digite 1:\nPara sair digite -1: ");
        scanf("%d", &opcao);
        fflush(stdin); // Limpar o buffer
        if(opcao == 1){
            printf("Digite a palavra: ");
            getline(&palavra, &tamanho_palavra, stdin); // Função que automaticamente lê o stdin e aloca memoria para a variavel
            system("cls");
            tamanho_palavra = strlen(palavra);
            jogo(palavra, tamanho_palavra);
        }
    }
    system("pause");
}
