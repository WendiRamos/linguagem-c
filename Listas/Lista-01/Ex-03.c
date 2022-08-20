#include <stdio.h>
#include <math.h>

int main()
{
    int numero;
    float resultado;

    printf("Entre um numero inteiro: ");
    scanf("%d", &numero);

    if (numero == 0)
    {
        printf("O numero digitado e' zero!");
    }
    else if (numero < 0)
    {
        resultado = pow(numero, 2);
        printf("Quadrado de %d: %.0f", numero, resultado);
    }
    else
    {
        resultado = sqrt(numero);
        printf("Raiz quadrada de %d: %f", numero, resultado);
    }
    return 0;
}