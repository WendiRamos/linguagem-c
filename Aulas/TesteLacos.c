#include <stdio.h>

int main(void)
{
    int numero;

    printf("Entre com um numero inteiro:");
    scanf("%d", &numero);
    if (numero % 2 == 0)
    {
        printf("O numero %d e par. \n", numero);
    }
    else
    {
        printf("O numero %d e impar. \n", numero);
    }
}