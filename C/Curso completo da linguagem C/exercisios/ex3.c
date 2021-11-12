#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL, "Portuguese");
    int n1, n2, n3;
    printf("Insira os três valores em sequencia: \n");
    scanf("%d %d %d", &n1, &n2, &n3); // Leitura semelheante a concatenação diga-se de passagem
    printf("O resultado da multiplicação dos valores %d, %d e %d é: %d\n", n1, n2, n3, (n1*n2*n3));
    system("pause");
}
