#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL, "Portuguese");
    int a = 6;
    if(a == 5){
        printf("a é igual 5\n");
    }
    else if(a == 6){
        printf("pode-se dizer que a é igual a 6\n");
    }
    else{
        printf("a = %d\n", a);
    }
    if(a % 2 != 0){
        printf("a é impar\n");
    }
    else{
        printf("a é par\n");
    }
    system("pause");
}