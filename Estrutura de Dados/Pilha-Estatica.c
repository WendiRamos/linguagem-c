#include <stdio.h>
#define TAM 5


typedef struct conteiner
{
    int id;
    int topo;
    char proprietario[60];
    char dataFabricacao[11];
} CONTEINER;

void inicializar(CONTEINER *pilha)
{
    pilha->topo = -1;
}

int pilhaVazia(CONTEINER *pilha)
{
    if (pilha->topo == -1)
    {
        return 1;
    }
    return 0;
}

int pilhaCheia(CONTEINER *pilha)
{
    if (pilha->topo == (TAM - 1))
    {
        return 1;
    }
    return 0;
}

int push(CONTEINER *pilha, int elemento)
{
    if (pilhaCheia(pilha))
    {
        printf("ERRO: Pilha Cheia.\n");
        return 0;
    }
    pilha->elem[pilha->topo + 1] = elemento;
    pilha->topo++;
    return 1;
}

int pop(CONTEINER *pilha)
{
    int removido = -1;
    if (pilhaVazia(pilha))
    {
        printf("Nao ha elemento para remover.\n");
        return removido;
    }
    removido = pilha->elem[pilha->topo];
    pilha->topo--;
    return removido;
}

int topoElem(CONTEINER *pilha)
{
    int topo = -1;
    if (pilhaVazia(pilha))
    {
        printf("Nao ha elemento.\n");
        return topo;
    }
    topo = pilha->elem[pilha->topo];
    return topo;
}

int main(void)
{
    CONTEINER p;
    return 0;
}