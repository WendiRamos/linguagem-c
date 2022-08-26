#include <stdio.h>

int main(void)
{
    int i, j, n;
    //FOR
    for (i = 3; i >= 0; i--)
    {
        if (i % 7 == 0)
        {
            printf("%d\n", i);
            break; // para o laço que estiver dentro!
            // continue; // se for compativel com o laço
        }

        for (j = 3; j >= 0; j--)
        {
            printf("*\t"); // \t é tabulação, como se usasse o tab
        }
        printf("\n");
    }

    //WHILE
    j = 1;
    while (j != 2)
    {
        scanf("%d", &j);
    }

    //DO WHILE
    do
    {
        printf("Digite um numero: ");
        scanf("%d", &n);
    } while (n != 0);

    return 0;
}