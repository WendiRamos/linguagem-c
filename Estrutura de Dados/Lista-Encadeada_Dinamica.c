#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Marques
typedef struct sPessoa
{
    char nome[50];
    int matricula;
} PESSOA;

typedef struct sCelula
{
    PESSOA info;
    struct sCelula *next;

} CELULA;

// Minha parte
typedef struct sNo
{
    int cont;
    struct sNo *prox;
} No;

void inicializarLista(No **lista)
{
    (*lista) = NULL;
}

No *novoNo(int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo != NULL)
    {
        novo->cont = valor;
        novo->prox = NULL;
    }
    else
    {
        printf("Erro ao alocar!\n");
    }
    return novo;
}

int listaVazia(No **lista)
{
    if (*lista == NULL)
    {
        return 1;
    }
    return 0;
}

int inserirFim(No **lista, int valor)
{
    No *novo = novoNo(valor);
    if (novo == NULL)
    {
        return 0;
    }

    if (listaVazia(lista))
    {
        *lista = novo;
        return 1;
    }

    No *aux = *lista;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->prox = novo;
    return 1;
}

int imprimirLista(No **lista)
{
    if (listaVazia(lista))
    {
        printf("Lista Vazia!\n");
        return 0;
    }

    No *aux = *lista;
    do
    {
        printf("%d\t", aux->cont);
        aux = aux->prox;
    } while (aux != NULL);
    printf("\n");
    return 1;
}

int inserirInicio(No **lista, int valor)
{
    No *novo = novoNo(valor);
    if (novo == NULL)
    {
        return 0;
    }

    if (listaVazia(lista))
    {
        return inserirFim(lista, valor);
    }

    novo->prox = *lista;
    *lista = novo;
    return 1;
}

// Remover nó do inicio (Marques)
PESSOA removerInicio(CELULA **lista)
{
    // Ponteiro p/ armazenar o end. da célula a ser removida
    CELULA *removida;

    // Elemento vazio
    PESSOA removido;
    strcpy(removido.nome, " ");
    removido.matricula = -1;

    // Se lista vazia, então não remove
    if (listaVazia(lista))
    {
        printf("Lista Vazia!\n");
        return removido;
    }

    // Guarda end. 1º elemento
    removida = *lista;
    removido = removida->info;

    // Faz a lista apontar para 2º elemento
    *lista = (*lista)->next;

    // Remove o antigo 1º elemento
    free(removida);
    return removido;
}

PESSOA criarPessoa(char nome[], int matricula)
{
    PESSOA pessoa;
    strcpy(pessoa.nome, nome);
    pessoa.matricula = matricula;

    return pessoa;
}

// Remover nó do final (Marques)
PESSOA removerFim(CELULA **lista)
{
    // Armazena o end. do nó a ser removido
    CELULA *removida;

    // Guarda o end. do nó que passará a ser o último
    CELULA *anterior;

    PESSOA removido = criarPessoa("", -1);

    if (listaVazia(lista))
    {
        printf("Lista Vazia!\n");
        return removido;
    }

    // Verifica se há apenas 1 elemento.
    if ((*lista)->next == NULL)
    {
        return removerInicio(lista);
    }

    // O ponteiro removida percorrerá a lista para encontrar
    // a posição onde deverá remover o item.
    removida = (*lista);
    while (removida->next != NULL)
    {
        anterior = removida;
        removida = removida->next;
    }

    removido = removida->info;
    anterior->next = NULL;
    free(removida);
    return removido;
}

//Pesquisar pela matrícula(Marques)
CELULA *pesquisarMatr(CELULA **lista, int mat){
    CELULA *auxiliar;

    if(listaVazia(lista)){
        printf("Lista Vazia!\n");
        return NULL;
    }

    auxiliar = (*lista); //Recebe o primeiro elemento da lista
    while(auxiliar != NULL){
        if(auxiliar->info.matricula == mat){
            return auxiliar;
        }
        //Se não encontrou, continuar procurando
        auxiliar = auxiliar->next;
    }
    return NULL; //Caso em que não há o elemento procurado
}

//Remover pela matrícula(Marques)
PESSOA removeMatr(CELULA **lista, int mat){
    CELULA *removida;
    CELULA *anterior;
    PESSOA pRemover = criarPessoa(" ", -1);

    if(listaVazia(lista)){
        printf("Lista Vazia!\n");
        return pRemover;
    }
    //Pesquisa pela matrícula
    removida = pesquisarMatr(lista, mat);
    if(removida == NULL){
        printf("Matricula nao encontrada\n");
        return pRemover;
    }
    //Caso seja o primeiro elemento
    if(removida == (*lista)){
        return removerInicio(lista);
    }
    //Copia o conteudo da célula a ser removida
    //Como sei esse conteudo? Pela função pesquisaMatr
    pRemover = removida->info;

    anterior = (*lista);
    //Encontra célula/nó anterior ao que será removido
    while(anterior->next != removida){
        anterior = anterior->next;
    }

    //Movimenta o ponteiro. O anterior deve apontar p/ onde o removido aponta
    anterior->next = removida->next;
    free(removida);

    return pRemover;
}


int main()
{
    No *lista;
    inicializarLista(&lista);

    printf("\n%d", listaVazia(&lista)); // O \n está no lugar errado.
    inserirFim(&lista, 1);
    imprimirLista(&lista);
    inserirFim(&lista, 2);
    imprimirLista(&lista);
    inserirInicio(&lista, 0);
    imprimirLista(&lista);
    inserirInicio(&lista, -1);
    imprimirLista(&lista);
    inserirFim(&lista, 3);
    imprimirLista(&lista);

    // duas lista aponta para o mesmo nó, sendo assim lista *lista perde seus antigos elementos
    // No *q;
    // q = novoNo(18);
    //*lista = q;

    return 0;
}
