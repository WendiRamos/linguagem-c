#include <stdio.h>
int main(void)
{
    float resultado = 0;
    int contador;

    for (contador = 1000; contador <= 1999; contador++)
    {
        if (contador % 13 == 5)
        {
            printf("%d\t",contador);
        }
    }
    return 0;
}