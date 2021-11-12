#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

void main(){
    setlocale(LC_ALL, "Portuguese");
    int numero[8], base2[8] = {128, 64, 32, 16, 8, 4, 2, 1}, soma = 0;
    bool is_binary = true;
    printf("Digite o valor do binario (1 byte): ");
    scanf("%d %d %d %d %d %d %d %d", &numero[0], &numero[1], &numero[2], &numero[3], &numero[4], &numero[5], &numero[6], &numero[7]);
    for(int x=0; x < 8; x++){
        if(numero[x] != 0 && numero[x] != 1){
            is_binary = false;
            break;
        }
    }
    if(is_binary == true){
        for(int x = 0; x < 8; x++){
            soma += numero[x] * base2[x];
        }
        printf("O valor do binario %d%d%d%d%d%d%d%d em decimal é: %d\n", numero[0], numero[1], numero[2], numero[3], numero[4], numero[5], numero[6], numero[7], soma);
    }
    else
        puts("O número não é binario!\n");
    system("pause");
}
