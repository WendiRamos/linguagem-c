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
    int opcao, elemento;
    FILA fila;
    inicializar(&fila);
    do
    {
        printf("*** MENU PRINCIPAL ***\n");
        printf("[1] - VERIFICAR SE FILA ESTA VAZIA\n");
        printf("[2] - VERIFICAR SE FILA ESTA CHEIA\n");
        printf("[3] - ENFILEIRAR\n");
        printf("[4] - DESENFILEIRAR\n");
        printf("[5] - IMPRIMIR FILA\n");
        printf("[6] - IMPRIMIR FILA E MANTER\n");
        printf("[0] - FINALIZAR PROGRAMA\n");
        printf(">>> OPCAO: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            printf("VERIFICAR SE PILHA ESTA VAZIA\n");
            if (filaVazia(&fila))
            {
                printf("Fila Vazia!\n\n");
            }
            else
            {
                printf("Fila nao esta vazia!\n\n");
            }
            break;
        case 2:
            printf("VERIFICAR SE PILHA ESTA CHEIA\n");
            if (filaCheia(&fila))
            {
                printf("Fila Cheia!\n\n");
            }
            else
            {
                printf("Fila nao esta cheia!\n\n");
            }
            break;
        case 3:
            printf("ENFILEIRAR\n");
            printf("Entre o numero para enfileirar: ");
            scanf("%d", elemento);
            enfileirar(&fila, elemento);
            break;
        case 4:
            printf("DESENFILEIRAR\n");
            desenfileirar(&fila);
            break;
        case 5:
            printf("IMPRIMIR FILA\n");
            imprimirFila(&fila);
            break;
        case 6:
            printf("IMPRIMIR FILA E MANTER\n");
            imprimirManterFila(&fila);
            break;
        default:
        {
            if (opcao == 0)
            {
                printf("Obrigada!");
            }
            else
            {
                printf("Escolha um numero de 1 a 6\n");
            }
            break;
        }
        }

    } while (opcao != 0);

    return 0;
}
