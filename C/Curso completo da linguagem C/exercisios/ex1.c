#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL, "Portuguese");
    float nota_1, nota_2, media;
    printf("Insira o valor da primeira nota: \n");
    scanf("%f", &nota_1);
    printf("Insira o valor da segunda nota: \n");
    scanf("%f", &nota_2);
    media = (nota_1 + nota_2) / 2;
    printf("A média das notas %.2f e %.2f é: %.2f\n", nota_1, nota_2, media); // %.2f = Para exibir somente duas casas decimais
    system("pause");
}
