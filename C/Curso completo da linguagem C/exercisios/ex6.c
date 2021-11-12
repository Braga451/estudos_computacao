#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL,"Portuguese");
    float valor_1, valor_2;
    int opcao;
    printf("Insira os dois valores: \n");
    scanf("%f %f", &valor_1, &valor_2);
    printf("Digite: \n1 para somar\n2 para subtrair\n3 para dividir\n4 para multiplicar\n");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            printf("%.2f + %.2f = %.2f", valor_1, valor_2, valor_1 + valor_2);
            break;
        case 2:
            printf("%.2f - %.2f = %.2f", valor_1, valor_2, valor_1 - valor_2);
            break;
        case 3:
            printf("%.2f/%.2f = %.2f", valor_1, valor_2, valor_1 / valor_2);
            break;
        case 4:
            printf("%.2f * %.2f = %.2f", valor_1, valor_2, valor_1 * valor_2);
            break;
        default:
            printf("Valor invalido!");
            break;
    }
    puts("\n");
    system("pause");
}
