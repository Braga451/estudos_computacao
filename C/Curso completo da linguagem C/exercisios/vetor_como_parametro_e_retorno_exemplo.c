#include <stdio.h>
#include <stdlib.h>

float* calculo_vetor(int * vetor, int tamanho_vetor){
    float * vetor_retorno;
    float media_valores, soma=0;
    int menor_valor = vetor[0], maior_valor = vetor[0], x = 0, qtd_valores = 0;
    vetor_retorno = malloc(3 * sizeof(float));
    for(x; x < tamanho_vetor; x++){
        soma+= vetor[x];
        qtd_valores++;
        if(vetor[x] > maior_valor){
            maior_valor = vetor[x];
        }
        if(vetor[x] < menor_valor){
            menor_valor = vetor[x];
        }
        if(vetor[x] < 0){
            break;
        }
    }
    media_valores = soma / qtd_valores;
    vetor_retorno[0] = media_valores;
    vetor_retorno[1] = menor_valor;
    vetor_retorno[2] = maior_valor;
    return vetor_retorno;
}

void main(){
    int * vetor;
    float * vetor_funcao_retorno;
    int tamanho_vetor;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &tamanho_vetor);
    if(tamanho_vetor > 0){
        vetor = malloc(tamanho_vetor * sizeof(int));
        for(int x = 0; x < tamanho_vetor; x++){
            printf("Insira o %d número: ", x+1);
            scanf("%d", &vetor[x]);
        }
        vetor_funcao_retorno = calculo_vetor(vetor, tamanho_vetor);
        printf("A media dos valores é de: %.2f", vetor_funcao_retorno[0]);
        printf("\nO menor valor é: %.0f", vetor_funcao_retorno[1]);
        printf("\nO maior valor é: %.0f", vetor_funcao_retorno[2]);
        free(vetor_funcao_retorno);
    }
    else{
        printf("Tamanho invalido de vetor!");
    }
    puts("\n");
    system("pause");
}
