#include <stdio.h>
#include <stdlib.h>

int * selectionSort(int * array, int tamanho){
    int * ordenado = (int *) malloc(tamanho * sizeof(int)), posicaoMenorValor, aux;
    for(int x = 0; x < tamanho; x++)
        ordenado[x] = array[x];
    for(int x = 0; x < tamanho; x++){
        posicaoMenorValor = x;
        for(int y = x + 1; y < tamanho; y++){
            if(ordenado[y] < ordenado[x]){
                posicaoMenorValor = y;
            }
        }
        if(posicaoMenorValor != x){
        aux = ordenado[x];
        ordenado[x] = ordenado[posicaoMenorValor];
        ordenado[posicaoMenorValor] = aux;
        }
    }
    return ordenado;
}

void main(){
    int * array, * ordenado, tamanho, valor_a_ser_inserido;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);
    array = (int *) malloc(tamanho * sizeof(int));
    for(int x = 0; x < tamanho; x++){
        printf("Digite o valor a ser inserido na posição %d: ", x);
        scanf("%d", &valor_a_ser_inserido);
        array[x] = valor_a_ser_inserido;
    }
    ordenado = selectionSort(array, tamanho);
    printf("Vetor original: ");
    for(int x = 0; x < tamanho; x++){
        printf("%d ", array[x]);
    }
    puts("");
    printf("Vetor ordenado: ");
    for(int x = 0; x < tamanho; x++){
        printf("%d ", ordenado[x]);
    }
}
