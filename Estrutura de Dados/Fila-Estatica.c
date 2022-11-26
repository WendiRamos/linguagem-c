#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct fila
{
    int elem[TAM];
    int cabecalho, ultimo;
} FILA;

void inicializar(FILA *fila)
{
    fila->ultimo = 0;
    fila->cabecalho = fila->ultimo;
}

int filaVazia(FILA *fila)
{
    return (fila->ultimo == fila->cabecalho);
}

int filaCheia(FILA *fila)
{
    int proxi = (fila->ultimo + 1) % TAM;
    return (proxi == fila->cabecalho);
}

int enfileirar(FILA *fila, int elemento)
{
    int proxi;
    if (filaCheia(fila))
    {
        return 0;
    }
    proxi = (fila->ultimo + 1) % TAM;
    fila->elem[proxi] = elemento;
    fila->ultimo = proxi;
    return 1;
}

int desenfileirar(FILA *fila)
{
    int removido = -1;
    if (filaVazia(fila))
    {
        return removido;
    }
    fila->cabecalho = (fila->cabecalho + 1) % TAM;
    removido = fila->elem[fila->cabecalho];
    return removido;
}

void imprimirFila(FILA *fila)
{
    if (filaVazia(fila))
    {
        printf("ERRO: Fila vazia!\n");
    }
    while (!filaVazia(fila))
    {
        printf("%d\t", desenfileirar(fila));
    }
    printf("\n");
}

void imprimirManterFila(FILA *fila)
{
    int removido;

    FILA aux;
    inicializar(&aux);

    if (filaVazia(fila))
    {
        printf("ERRO: Fila vazia!\n");
    }
    while (!filaVazia(fila))
    {
        removido = desenfileirar(fila);
        enfileirar(&aux, removido);
        printf("%d\t", removido);
    }
    while (!filaVazia(&aux))
    {
        enfileirar(fila, desenfileirar(&aux));
    }
    printf("\n");
}

int main()
{
    FILA fila;
    inicializar(&fila);
    enfileirar(&fila, 3);
    enfileirar(&fila, 4);
    enfileirar(&fila, 5);
    enfileirar(&fila, 6);
    enfileirar(&fila, 7);
    enfileirar(&fila, 8);
    enfileirar(&fila, 9);
    printf("%d\n", desenfileirar(&fila));
    imprimirManterFila(&fila);
    imprimirFila(&fila);
    return 0;
}