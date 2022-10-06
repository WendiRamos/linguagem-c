/*
Descrição: Programa para geração de matriz alocada dinamicamente.
Autor: Marques Sousa
Data: 30/09/2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL)); // Define a semente do rand com base no clock.
    int **matriz, i, j, k;
    int linhas, colunas;

    printf("Entre com o numero de linhas: \n");
    scanf("%d", &linhas);
    printf("Entre com o numero de colunas: \n");
    scanf("%d", &colunas);

    // Aloca a matriz dinamicamente.
    matriz = (int **)malloc(linhas * sizeof(int *));
    for (i = 0; i < linhas; i++)
    {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }
    // Realiza o prenchimento da matriz de forma aleatória.
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            matriz[i][j] = (rand() % 60) + 1; // Gera número no intervalo [1, 60]

            // Força a geração de um novo número que já está naquela linha.
            for (k = 0; k < j; k++)
            {
                if (matriz[i][j] == matriz[i][k])
                { // Se igual, gera novamente
                    j--;
                    break;
                }
            }
        }
    }
    // Imprime a matriz.
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    // Libera a memória alocada para cada linha da matriz.
    for (i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    matriz = NULL;
    return 0;
}

// // Errado
// int a = 5;
// int *p = NULL;
// *p = a;

// // Errado
// int a = 5;
// int *p = NULL;
// *p = &a;

// // Certo
// int a = 5;
// int *p = NULL;
// p = &a;

// // Certo
// int *p;
// p = (int *)malloc(sizeof(int));
// *p = 5;