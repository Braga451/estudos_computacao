#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main(){
    setlocale(LC_ALL, "Portuguese");
    int matriz_normal[2][2], matriz_ao_contrario[2][2], x, y, reverse = 1;
    for(x = 0; x < 2; x++){
        for(y = 0; y < 2; y++){
            printf("Insira um valor: ");
            scanf("%d", &matriz_normal[x][y]);
        }
    }
    printf("A matriz original é: \n%d %d \n%d %d", matriz_normal[0][0], matriz_normal[0][1], matriz_normal[1][0], matriz_normal[1][1]);
    for(x = 0; x < 2; x++){
        for(y = 0; y < 2; y++){
            matriz_ao_contrario[x][y] = matriz_normal[reverse][y];
        }
        reverse--;
    }
    puts("\n");
    printf("A matriz reversa é: \n%d %d \n%d %d\n", matriz_ao_contrario[0][0], matriz_ao_contrario[0][1], matriz_ao_contrario[1][0], matriz_ao_contrario[1][1]);
	system("pause");
}

/*Mini explicação
[0][0] = [1][0]
[0][1] = [1][1]
[1][0] = [0][0]
[1][1] = [0][1]

Basicamente o programa precisaria fazer isso, pode-se observar que os parametros y se acompanham, enquanto os de x são reversos, logo, precisariamos 
de uma variavel que inicializa-se com o parametro 1 e reduzisse 1 apos a execução.

Codigo do professor:
Versão 1:
    #include <stdio.h>
    #include <stdlib.h>
    #include <locale.h>
     
    void main() {
     
        //Para usar acentos
        setlocale(LC_ALL,"");
     
        //Preencha uma matriz 2x2 lendo valores do usuário e
        //depois troque os valores entre a primeira e a segunda linha.
        int minhaMatriz[2][2], aux1,aux2, i , j;
     
        //Lendo valores para matriz
        printf("Digite um valor para [0][0]");
        scanf("%d", &minhaMatriz[0][0]);
        printf("Digite um valor para [0][1]");
        scanf("%d", &minhaMatriz[0][1]);
        printf("Digite um valor para [1][0]");
        scanf("%d", &minhaMatriz[1][0]);
        printf("Digite um valor para [1][1]");
        scanf("%d", &minhaMatriz[1][1]);
     
        //Auxiliares
        aux1 = minhaMatriz[0][0];
        aux2 = minhaMatriz[0][1];
     
        //Invertendo valores usando auxiliares
        minhaMatriz[0][0] = minhaMatriz[1][0];
        minhaMatriz[0][1] = minhaMatriz[1][1];
        minhaMatriz[1][0] = aux1;
        minhaMatriz[1][1] = aux2;
     
        //Imprimindo nova matriz
        printf("\n%d %d",minhaMatriz[0][0],minhaMatriz[0][1]);
        printf("\n%d %d",minhaMatriz[1][0],minhaMatriz[1][1]);
     
    }

Versão 2:
    #include <stdio.h>
    #include <stdlib.h>
    #include <locale.h>
     
    void main() {
     
        //Para usar acentos
        setlocale(LC_ALL,"");
     
        //Preencha uma matriz 2x2 lendo valores do usuário e
        //depois troque os valores entre a primeira e a segunda linha.
        int minhaMatriz[2][2], aux1,aux2, i , j;
     
        //Lendo valores para matriz
        for(i = 0; i < 2 ; i++){
            for(j = 0; j < 2 ; j++){
                printf("Digite um valor para [%d][%d]:", i, j);
                scanf("%d", &minhaMatriz[i][j]);
            }
        }
     
        //Auxiliares
        aux1 = minhaMatriz[0][0];
        aux2 = minhaMatriz[0][1];
     
        //Invertendo valores usando auxiliares
        minhaMatriz[0][0] = minhaMatriz[1][0];
        minhaMatriz[0][1] = minhaMatriz[1][1];
        minhaMatriz[1][0] = aux1;
        minhaMatriz[1][1] = aux2;
     
        //Imprimindo nova matriz
        for(i = 0; i < 2 ; i++){
            for(j = 0; j < 2 ; j++){
                printf("%d ", minhaMatriz[i][j]);
            }
            printf("\n");
        }
    }*/