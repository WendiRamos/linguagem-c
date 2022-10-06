#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int **matriz, x, y, z;
    int linhas, colunas;

    printf("Entre com o numero de linhas: \n");
    scanf("%d", &linhas);
    printf("Entre com o numero de colunas: \n");
    scanf("%d", &colunas);

    matriz = (int **)malloc(linhas * sizeof(int *));
    for (x = 0; x < linhas; x++)
    {
        matriz[x] = (int *)malloc(colunas * sizeof(int));
    }
    
    for (x = 0; x < linhas; x++)
    {
        for (y = 0; y < colunas; y++)
        {
            matriz[x][y] = (rand() % 100) + 1;
        }
    }
    
    for (x = 0; x < linhas; x++)
    {
        for (y = 0; y < colunas; y++)
        {
            printf("%d\t", matriz[x][y]);
        }
        printf("\n");
    }
    
    for (x = 0; x < linhas; x++)
    {
        free(matriz[x]);
    }
    free(matriz);
    matriz = NULL;
    return 0;
}
