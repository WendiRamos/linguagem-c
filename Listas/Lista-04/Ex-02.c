#include <stdio.h>
#include <stdlib.h>
#define maxTam 10

typedef struct sLista
{
    char elemento[maxTam];
    int ultimo;
} Lista;

// Inicializar a lista
void inicializarLista(Lista *lista)
{
    lista->ultimo = -1;
}

// Verificar se a lista esta vazia
int listaVazia(Lista *lista)
{
    if (lista->ultimo == -1)
    {
        return 1;
    }
    return 0;
}

//Verificar se a lista esta cheia
int listaCheia(Lista *lista){
    if(lista -> ultimo == (maxTam -1)){
        return 1;
    }
    return 0;
}

//Inserir elemento no fim da lista
int inserirFim(Lista *lista, char elemento){
    //Verificar se a lista está cheia
    if(listaCheia(lista)){
        printf("ERRO: Lista cheia!\n");
        return 0;
    }
    lista -> elemento[lista -> ultimo + 1] = elemento;
    lista -> ultimo++;
    return 1;
}

// Exibir todos os elemento da lista
int exibirLista(Lista *lista)
{
    int i;

    if (!listaVazia(lista))
    {
        for (i = 0; i <= lista->ultimo; i++)
        {
            printf("%c\t", lista->elemento[i]);
        }
        return 0;
    }
    else
    {
        printf("Lista Vazia!");
    }
}

//Inserir elemento em posição k informada


int main()
{
    Lista lista;
    inicializarLista(&lista);
    inserirFim(&lista, 'w');
    inserirFim(&lista, 'e');
    inserirFim(&lista, 'n');
    inserirFim(&lista, 'd');
    inserirFim(&lista, 'i');
    exibirLista(&lista);

    return 0;
}