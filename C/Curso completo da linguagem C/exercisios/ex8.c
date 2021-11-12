#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL, "Portuguese");
    int c = 10;
    printf("Usando for:\n");
    for(c; c <= 20; c += 2){
        printf("%d\n", c);
    }
    printf("Usando while:\n");
    c = 10;
    while(c <= 20){
        printf("%d\n", c);
        c +=2;
    }
    printf("Usando do while:\n");
    c = 10;
    do{
        printf("%d\n", c);
        c += 2;
    }while(c <= 20);
    system("pause");
}
