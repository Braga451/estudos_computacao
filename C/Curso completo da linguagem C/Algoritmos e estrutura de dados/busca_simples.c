#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool buscaSimples(int * vetor, int valor_procurado, int tamanho_vetor){
    bool valor_foi_encontrado = false;
    for(int x = 0; x < tamanho_vetor; x++){
        if(vetor[x] == valor_procurado){
            valor_foi_encontrado = true;
            printf("Valor [%d] encontrado na posição %d", valor_procurado, x);
        }
    }
    if(valor_foi_encontrado == false)
        printf("Valor não encontrado!");
    return valor_foi_encontrado;
}

void main(){
    bool foi_encontrado;
    int tamanho_vetor, valor_procurado;
    int * vetor;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho_vetor);
    vetor = (int *) malloc(tamanho_vetor * sizeof(int));
    for(int x = 0; x < tamanho_vetor; x++){
        printf("Digite o valor na posição %d: ", x);
        scanf("%d", &vetor[x]);
    }
    printf("Digite o valor procurado: ");
    scanf("%d", &valor_procurado);
    foi_encontrado = buscaSimples(vetor, valor_procurado, tamanho_vetor);
    free(vetor);
}
