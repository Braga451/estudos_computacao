#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL, "Portuguese");
    int c = 10;
    printf("----------Contagem regressiva com for----------\n");
    for(c; c >= 0; c--){
        printf("%d\n", c);
    }
    c = 10;
    printf("----------Fim da contagem----------\n");
    printf("----------Contagem regressiva com while----------\n");
    while(c >= 0){
        printf("%d\n", c);
        c--;
    }
    printf("----------Fim da contagem----------\n");
    printf("----------Contagem regressiva com do while----------\n");
    c = 10;
    do{
        printf("%d\n", c);
        c--;
    }while(c >= 0);
    printf("----------Fim da contagem----------\n");
    system("pause");
}
