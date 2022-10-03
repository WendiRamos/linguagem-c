#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, num, *x;

    printf("Informe o tamanho do vetor: \n");
    scanf("%d", &num);

    x = (int *)malloc(num * sizeof(int));
    if (x == NULL)
    {
        printf("Nao foi possivel alocar memoria. \n");
        exit(0);
    }

    for (i = 0; i < num; i++)
    {
        printf("Digite o valor para a posicao %d do vetor: ", i + 1);
        scanf("%d", &x[i]);
    }

    printf("\nVetor: \n");
    for (i = 0; i < num; i++)
    {
        printf("%d\n", x[i]);
    }

    free(x);
    return 0;
}