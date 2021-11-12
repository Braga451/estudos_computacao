#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL, "Portuguese");
    float nota_1, nota_2, nota_3, resultado;
    printf("Insira o valor das três notas: ");
    scanf("%f %f %f", &nota_1, &nota_2, &nota_3);
    resultado = (nota_1 + nota_2 + nota_3)/3;
    printf("O resultado foi: %.2f\n", resultado);
    if(resultado > 7){
        printf("O aluno foi aprovado!\n");
    }
    else{
        printf("O aluno foi reprovado!\n");
    }
    system("pause");
}
