#include <stdio.h>

int main(void)
{
    int n, valoresEncontrados = 0, i = 1;
    do
    {
        printf("Entre um numero positivo: ");
        scanf("%d", &n);
    } while (n <= 0);

    while (valoresEncontrados < n)
    {
        if (i % 4 == 0 && i % 7 == 0)
        {
            printf("%d\t", i);
            valoresEncontrados++;
        }
        i++;
    }
    return 0;
}