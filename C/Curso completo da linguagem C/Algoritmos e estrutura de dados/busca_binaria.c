#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool buscaBinaria(int * vetor_inteiros, int tamanho_vetor, int valor_procurado){
    bool foi_encontrado = false;
    int esquerda = 0, direita = tamanho_vetor - 1, pivo;
    while(esquerda <= direita){
        pivo = (esquerda + direita)/2;
        if(vetor_inteiros[pivo] == valor_procurado){
            printf("Valor[%d] encontrado na posição: %d", valor_procurado, pivo);
            foi_encontrado = true;
            return foi_encontrado;
        }
        if(vetor_inteiros[pivo] < valor_procurado){
            esquerda = pivo + 1;
        }
        else{
            direita = pivo - 1; //Interessante notar que para fazer as aleterações tanto a esquerda, como a direita, sempre se baseiam no valor do pivo (meio). 
                                //Digo isto pois errei, inicialmente, colocando aqui o valor da esquerda - 1. 
                                //O que, caso o algoritmo iniciasse com o pivo sendo menor que o valor solicitado, ele iria pegar o valor da esquerda (0) - 1, ou seja -1.
                                //Isso acaba por resultar em uma situação onde, no começo do algoritmo, o valor da esquerda torna-se maior que o da direita. 
                                //Assim, terminando a busca.
        }
    }
    if(foi_encontrado == false)
        printf("Valor %d não foi encontrado!", valor_procurado);
        return foi_encontrado;
}

void main(){
    bool foi_encontrado;
    int * vetor_inteiros;
    int tamanho_vetor, valor_procurado, posicao_valor;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho_vetor);
    vetor_inteiros = (int *) malloc(tamanho_vetor * sizeof(int));
    for(int x = 0; x < tamanho_vetor; x++){
        printf("Digite o valor na posição[%d]: ", x);
        scanf("%d", &vetor_inteiros[x]);
    }
    printf("Digite o valor procurado: ");
    scanf("%d", &valor_procurado);
    foi_encontrado = buscaBinaria(vetor_inteiros, tamanho_vetor, valor_procurado);
}
