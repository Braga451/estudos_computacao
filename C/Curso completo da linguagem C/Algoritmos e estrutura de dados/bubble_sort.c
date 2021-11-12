#include <stdio.h>
#include <stdlib.h>

int * bubbleSort(int * array, int tamanho){
    int aux, * novo_array;
    novo_array = (int * ) malloc(tamanho * sizeof(int));
    for(int x = 0; x < tamanho; x++){
        novo_array[x] = array[x];
    }
    for(int x = 0; x < tamanho; x++){
        for(int y = x + 1; y < tamanho; y++){
            if(novo_array[x] > novo_array[y]){
                aux = novo_array[x];
                novo_array[x] = novo_array[y];
                novo_array[y] = aux;
            }
        }
    }
    return novo_array;
}

void main(){
    int * array, * lista_ordenada, tamanho, valor_a_ser_inserido;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    array = (int * ) malloc(tamanho * sizeof(int));
    for(int x = 0; x < tamanho; x++){
        printf("Digite o valor na posição %d: ", x);
        scanf("%d", &valor_a_ser_inserido);
        array[x] = valor_a_ser_inserido;    
    }
    lista_ordenada = bubbleSort(array, tamanho);
    printf("Lista original: ");
    for(int x = 0; x < tamanho; x++){
        printf("%d ", array[x]);
    }
    puts("");
    printf("Lista ordenada: ");
    for(int x = 0; x < tamanho; x++){
        printf("%d ", lista_ordenada[x]);
    }
    free(lista_ordenada);
    free(array);
}
