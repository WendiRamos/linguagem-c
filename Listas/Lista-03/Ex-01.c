#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x, *y;
    x = (int *)malloc(sizeof(int));
    y = (int *)malloc(sizeof(int));

    if (x == NULL || y == NULL)
    {
        printf("Nao foi possivel alocar memoria. \n");
        exit(0);
    }

    printf("Entre dois numeros inteiros: ");
    scanf("%d %d", x, y);

    printf("%d\t %d", *x, *y);
    free(x);
    free(y);
    return 0;
}
