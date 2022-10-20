#include <stdio.h>
#define MAX 10

typedef struct LISTA
{
    char elem[MAX];
    int ultimo;
} LISTA;

void inicializarLista(LISTA *lista)
{
    lista->ultimo = -1;
}

int listaCheia(LISTA *lista)
{
    if (lista->ultimo == MAX - 1)
    {
        return 1;
    }
    return 0;
}

int listaVazia(LISTA *lista)
{
    if (lista->ultimo == -1)
    {
        return 1;
    }
    return 0;
}

int inserirFim(LISTA *lista, char elemento)
{
    if (listaCheia(lista))
    {
        printf("ERRO: Lista cheia!\n");
        return 0;
    }
    lista->elem[++lista->ultimo] = elemento;
    return 1;
}

int exibirLista(LISTA *lista)
{
    int i;
    if (listaVazia(lista)) {
        printf("ERRO: Lista vazia!\n");
        return 0;
    }
    for (i = 0; i <= lista->ultimo; ++i)
    {
        printf("%c", lista->elem[i]);
    }
    printf("\n");
    return 1;
}

int inserirNaPosicao(LISTA *lista, char elemento, int posicao)
{
    int i;
    if (listaCheia(lista))
    {
        printf("ERRO: Lista cheia!\n");
        return 0;
    }
    if (posicao < 0 || posicao > lista->ultimo + 1)
    {
        printf("ERRO: Posicao invalida!\n");
        return 0;
    }
    lista->ultimo++;
    for ( i = lista->ultimo; i > posicao; i--)
    {
        lista->elem[i] = lista->elem[i - 1];
    }
    lista->elem[posicao] = elemento;
    return 1;
}

int inverterLista(LISTA *lista)
{
    int i, j;
    if (listaVazia(lista))
    {
        printf("ERRO: Lista vazia!\n");
        return 0;
    }
    for ( i = 0, j = lista->ultimo; i < j; i++, j--)
    {
        char aux = lista->elem[i];
        lista->elem[i] = lista->elem[j];
        lista->elem[j] = aux;
    }
    return 1;
}

int ordenarLista(LISTA *lista)
{
    int i,j;
    if (listaVazia(lista))
    {
        printf("ERRO: Lista vazia!\n");
        return 0;
    }
    for ( i = 0; i < lista->ultimo; i++)
    {
        for ( j = i + 1; j <= lista->ultimo; j++)
        {
            if (lista->elem[i] > lista->elem[j])
            {
                char aux = lista->elem[i];
                lista->elem[i] = lista->elem[j];
                lista->elem[j] = aux;
            }
        }
    }
    return 1;
}

int main(void)
{
    int opcao, posicao;
    char elemento;

    LISTA lista;
    inicializarLista(&lista);

    do
    {
        printf("*** MENU PRINCIPAL ***\n");
        printf("[1] - Exibir lista\n");
        printf("[2] - Inserir elemento no final da lista\n");
        printf("[3] - Inserir elemento na posicao K da lista\n");
        printf("[4] - Inverter lista\n");
        printf("[5] - Ordenar lista\n");
        printf("[0] - Finalizar programa\n");
        printf(">>> OPCAO: ");
        scanf("%d", &opcao);
        printf("\n");
        
        switch (opcao)
        {
            case 1:
                if (exibirLista(&lista)) printf("SUCESSO!\n\n");
                else printf("FALHA!\n\n");
                break;
            case 2:
                printf("Elemento: ");
                scanf(" %c", &elemento);
                if (inserirFim(&lista, elemento)) printf("SUCESSO!\n\n");
                else printf("FALHA!\n\n");
                break;
            case 3:
                printf("Elemento: ");
                scanf(" %c", &elemento);
                printf("Posicao: ");
                scanf("%d", &posicao);
                if (inserirNaPosicao(&lista, elemento, posicao)) printf("SUCESSO!\n\n");
                else printf("FALHA!\n\n");
                break;
            case 4:
                if (inverterLista(&lista)) printf("SUCESSO!\n\n");
                else printf("FALHA!\n\n");
                break;
            case 5:
                if (ordenarLista(&lista)) printf("SUCESSO!\n\n");
                else printf("FALHA!\n\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
