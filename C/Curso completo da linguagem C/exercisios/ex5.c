#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL, "Portuguese");
    int lado_1, lado_2, lado_3;
    printf("Insira os três lados: \n");
    scanf("%d %d %d", &lado_1, &lado_2, &lado_3);
    if(lado_1 == lado_2 && lado_2 == lado_3){
        printf("O triangulo equilatero pode ser formado!");
    }
    else{
        printf("O triangulo equilatero não pode ser formado!");
    }
    puts("\n");
    system("pause");
}
