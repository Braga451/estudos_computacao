#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL, "Portuguese");
    int input, c, verificador = 0;
    printf("Insira um valor: ");
    scanf("%d", &input);
    printf("O valor digitado foi: %d\n", input);
    for(c = 1; c <= input; c++){
        if(input % c == 0){
            verificador++;
        }
        printf("%d / %d posusi como resto da divisão %d\n", input, c, input % c);
    }
    printf("O número %d %s\n", input, verificador == 2 ? "é primo" : "não é primo"); // Solução usando operador ternario
    system("pause");
}
