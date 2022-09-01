#include <stdio.h>

int main(void)
{
    int a, b, i, resultado = 1;
    
    printf("Entre o numero base: ");
    scanf("%d", &b);

    printf("Entre o numero expoente: ");
    scanf("%d", &a);

    for (i = 0; i < a; i++)
    {
        resultado = resultado * b;
    }
    printf("O valor de %d elevado a %d sera de: %d", a, b, resultado);
    return 0;
}