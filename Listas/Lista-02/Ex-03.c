#include <stdio.h>

int main(void)
{
    float numero, resultado = 0;
    do
    {
        printf("Entre um numero: \n");
        scanf("%f", &numero);
        resultado = resultado + numero;
    } while (numero != 0);
    
    printf("Resultado da soma dos numeros digitados: %f", resultado);

    return 0;
}