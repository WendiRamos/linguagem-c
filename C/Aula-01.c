#include <stdio.h>

int main(void){
    int numero , quadrado;
    float fracao;
    char letra;

    printf("Entre com um caractere:");
    scanf("%c", &letra);

    printf("o caractere digitado foi %c \n", letra);

    printf("Entre com um numero inteiro:");
    scanf("%d", &numero);

    printf("Entre com um numero fracionario:");
    scanf("%f", &fracao);

    quadrado = numero * numero;

    printf("O quadrado e %d por %f e igual a %f. \n", quadrado, fracao, quadrado/fracao);
        
    return 0;
}
