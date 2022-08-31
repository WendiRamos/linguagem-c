#include <stdio.h>

int main(void)
{
    int resultadoImpar = 0, resultadoPar = 0, i, numero;

    for (i = 0; i < 12; i++)
    {
        do
        {
            printf("Digite o %d numero positivo: ", i+1);
            scanf("%d", &numero);
        } while (numero <= 0);

        if (numero % 2 == 0)
        {
            resultadoPar = resultadoPar + numero;
        }
        else
        {
            resultadoImpar = resultadoImpar + numero;
        }
    }
    printf("Resultado da soma dos numeros pares: %d\n", resultadoPar);
    printf("Resultado da soma dos numeros impares: %d", resultadoImpar);

    return 0;
}