#include <stdio.h>

int main()
{
    int numero;

    printf("Entre um numero inteiro: ");
    scanf("%d", &numero);

    if (numero % 4 == 0 && numero % 5 == 0)
    {
        printf("O numero %d e' divisivel por 4 e 5.", numero);
    }
    else if (numero % 4 == 0)
    {
        printf("O numero %d e' divisivel por 4.", numero);
    }
    else if (numero % 5 == 0)
    {
        printf("O numero %d e' divisivel por 5.", numero);
    }
    else
    {
        printf("O numero %d nao e' divisivel por 4 ou 5.", numero);
    }
    return 0;
}