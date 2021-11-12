#include <stdio.h>
#include <stdlib.h>


int * insertionSort(int * array, int quantidade_elementos){
    int * ordenado = (int *) malloc(quantidade_elementos * sizeof(int)), elemento_analisado, anterior;
    for(int x = 0; x < quantidade_elementos; x++){
        ordenado[x] = array[x];
    }
    for(int x = 1; x < quantidade_elementos; x++){
        elemento_analisado = ordenado[x];
        anterior = x - 1;
        while(anterior >= 0 && elemento_analisado < ordenado[anterior]){
            ordenado[anterior + 1] = ordenado[anterior];
            anterior--;
        }
        ordenado[anterior + 1] = elemento_analisado; 
    }
    return ordenado;
}

void main(){
    int * array, * novo_array, quantidade_elementos, numero_a_ser_inserido;
    printf("Digite a quantidade de elementos no vetor: ");
    scanf("%d", &quantidade_elementos);
    array = (int *) malloc(quantidade_elementos * sizeof(int));
    for(int x = 0; x < quantidade_elementos; x++){
        printf("Digite o valor a ser colocado na posição %d: ", x);
        scanf("%d", &numero_a_ser_inserido);
        array[x] = numero_a_ser_inserido;
    }
    novo_array = insertionSort(array, quantidade_elementos);
    printf("Array original: ");
    for(int x = 0; x < quantidade_elementos; x++){
        printf("%d ", array[x]);
    }
    puts("");
    printf("Array ordenado: ");
    for(int x = 0; x < quantidade_elementos; x++){
        printf("%d ", novo_array[x]);
    }
    free(array);
    free(novo_array);
}
