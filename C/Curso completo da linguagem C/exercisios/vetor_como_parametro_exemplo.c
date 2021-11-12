#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_verify(char * string){
    int tamanho_string = strlen(string), qtd_pontuacao = 0, qtd_numeros = 0, qtd_minusculas = 0;
    for(int x = 0; x < tamanho_string; x++){
        if(string[x] >= 33 && string[x] <= 47){
            qtd_pontuacao++;
        }
        else if(string[x] >= 48 && string[x] <= 57){
            qtd_numeros++;
        }
        else if(string[x] >= 97 && string[x] <= 122){
            qtd_minusculas++;
        }
    }
    printf("A string tem o tamanho: %d\nSendo o número de pontuações: %d\nSendo a quantidade de números: %d\nSendo a quantidade de minusculas de: %d", tamanho_string, qtd_pontuacao, qtd_numeros, qtd_minusculas);
}

void main(){
    char * string;
    string = malloc(81 * sizeof(char));
    printf("Insira a string: ");
    fgets(string, 81, stdin);
    string_verify(string);
    free(string);
    system("pause");
}
