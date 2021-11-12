#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL, "Portuguese");
    float nota_1, nota_2; 
    int valor_absoluto_diferenca;
    printf("Insira o primeiro valor: \n");
    scanf("%f", &nota_1);
    printf("Insira o segundo valor: \n");
    scanf("%f", &nota_2);
    valor_absoluto_diferenca = abs(nota_1 - nota_2); // Abs -> Retorna valor absoluto
    printf("\nO valor absoluto da diferença é: %d\n", valor_absoluto_diferenca);
    system("pause");
}
