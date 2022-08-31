#include <stdio.h>
#include <conio.h>
int main(void)
{
    int contador;
    float numero, numMaior, numMenor;

    for (contador = 0; contador < 12; contador++)
    {
        printf("Entre um numero: \n");
        scanf("%f", &numero);
        if (contador == 0)
        {
            numMaior = numero;
            numMenor = numero;
        }
        else if (numero > numMaior)
        {
            numMaior = numero;
        }
        else if (numero < numMenor)
        {
            numMenor = numero;
        }
    }
    printf("O numero menor: %f\n", numMenor);
    printf("O numero maior: %f", numMaior);
    return 0;
}