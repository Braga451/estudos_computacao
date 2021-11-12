#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*void main(){
    setlocale(LC_ALL, "Portuguese");
    int c = 0;
    float vetor_numerico[3], media = 0;
    for(c; c < 3; c++){
        printf("Insira um valor: ");
        scanf("%f", &vetor_numerico[c]);
        media += vetor_numerico[c];
    } 
    media /= 3;
    printf("A media dos números %.2f %.2f %.2f = %.2f ", vetor_numerico[0], vetor_numerico[1], vetor_numerico[2], media);
}
*/

void main(){
    setlocale(LC_ALL, "Portuguese");
    int c = 0, tamanho_vetor = 0;
    float media = 0;
    printf("Qual sera o tamanho do vetor?: ");
    scanf("%d", &tamanho_vetor);
    float vetor_numerico[tamanho_vetor];
    for(c; c < tamanho_vetor; c++){
        printf("Insira um número: ");
        scanf("%f", &vetor_numerico[c]);
        media += vetor_numerico[c];
    }
    media /= tamanho_vetor;
    printf("A media dos valores é de: %.2f", media);
}
