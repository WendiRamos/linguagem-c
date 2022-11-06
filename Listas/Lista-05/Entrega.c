#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sPessoa
{
    char nome[50];
    int matricula;
} PESSOA;

typedef struct sCelula
{
    PESSOA pessoa;
    struct sCelula *next;

} CELULA;

void inicializarLista(CELULA **lista)
{
    (*lista) = NULL;
}

CELULA *novaCelula(PESSOA pessoa)
{
    CELULA *celula = (CELULA *)malloc(sizeof(CELULA));
    if (celula != NULL)
    {
        celula->pessoa.matricula = pessoa.matricula;
        strcpy(celula->pessoa.nome, pessoa.nome);
        celula->next = NULL;
    }
    else
    {
        printf("Erro ao alocar!\n");
    }
    return celula;
}

PESSOA criarPessoa(char nome[], int matricula)
{
    PESSOA pessoa;
    strcpy(pessoa.nome, nome);
    pessoa.matricula = matricula;
    return pessoa;
}

int listaVazia(CELULA **lista)
{
    if (*lista == NULL)
    {
        return 1;
    }
    return 0;
}

int inserirFim(CELULA **lista, PESSOA pessoa)
{
    CELULA *celula = novaCelula(pessoa);
    if (celula == NULL)
    {
        return 0;
    }

    if (listaVazia(lista))
    {
        *lista = celula;
        return 1;
    }

    CELULA *aux = *lista;
    while (aux->next != NULL)
    {
        aux = aux->next;
    }
    aux->next = celula;
    return 1;
}

int imprimirLista(CELULA **lista)
{
    if (listaVazia(lista))
    {
        printf("Lista Vazia!\n\n");
        return 0;
    }

    CELULA *aux = *lista;
    do
    {
        imprimirPessoa(aux->pessoa);
        aux = aux->next;
    } while (aux != NULL);
    printf("\n");
    return 1;
}

int tamanhoLista(CELULA **lista)
{
    CELULA *aux = *lista;
    int cont = 0;

    while (aux != NULL)
    {
        cont++;
        aux = aux->next;
    }
    return cont;
}

int inserirInicio(CELULA **lista, PESSOA pessoa)
{
    CELULA *celula = novaCelula(pessoa);
    if (celula == NULL)
    {
        return 0;
    }

    if (listaVazia(lista))
    {
        return inserirFim(lista, pessoa);
    }

    celula->next = *lista;
    *lista = celula;
    return 1;
}

PESSOA removerInicio(CELULA **lista)
{
    CELULA *removida;

    PESSOA removido;
    strcpy(removido.nome, " ");
    removido.matricula = -1;

    if (listaVazia(lista))
    {
        printf("Lista Vazia!\n\n");
        return removido;
    }

    removida = *lista;
    removido = removida->pessoa;

    *lista = (*lista)->next;

    free(removida);
    return removido;
}

PESSOA removerFim(CELULA **lista)
{
    CELULA *removida;
    CELULA *anterior;
    PESSOA removido = criarPessoa("", -1);

    if (listaVazia(lista))
    {
        printf("Lista Vazia!\n");
        return removido;
    }

    if ((*lista)->next == NULL)
    {
        return removerInicio(lista);
    }

    removida = (*lista);
    while (removida->next != NULL)
    {
        anterior = removida;
        removida = removida->next;
    }

    removido = removida->pessoa;
    anterior->next = NULL;
    free(removida);
    return removido;
}

CELULA *pesquisarMatr(CELULA **lista, int mat)
{
    CELULA *auxiliar;

    if (listaVazia(lista))
    {
        printf("Lista Vazia!\n");
        return NULL;
    }

    auxiliar = (*lista);
    while (auxiliar != NULL)
    {
        if (auxiliar->pessoa.matricula == mat)
        {
            return auxiliar;
        }
        auxiliar = auxiliar->next;
    }
    return NULL;
}

PESSOA removeMatr(CELULA **lista, int mat)
{
    CELULA *removida;
    CELULA *anterior;
    PESSOA pRemover = criarPessoa(" ", -1);

    if (listaVazia(lista))
    {
        printf("Lista Vazia!\n");
        return pRemover;
    }
    removida = pesquisarMatr(lista, mat);
    if (removida == NULL)
    {
        printf("Matricula nao encontrada!\n\n");
        return pRemover;
    }

    if (removida == (*lista))
    {
        return removerInicio(lista);
    }

    pRemover = removida->pessoa;
    anterior = (*lista);

    while (anterior->next != removida)
    {
        anterior = anterior->next;
    }

    anterior->next = removida->next;
    free(removida);
    return pRemover;
}

PESSOA lerDadosPessoa()
{
    char nome[50];
    int matricula;
    printf("Entre com os dados da pessoa:\n");
    printf("NOME: ");
    scanf(" %[^\n]s", nome);
    printf("MATRICULA: ");
    scanf("%d", &matricula);
    return criarPessoa(nome, matricula);
}

int lerMatricula()
{
    int matricula;
    printf("Entre a matricula: ");
    scanf("%d", &matricula);
    return matricula;
}

void imprimirPessoa(PESSOA pessoa)
{
    printf("MATRICULA: %5d\t NOME: %s\n", pessoa.matricula, pessoa.nome);
}

void limparLista(CELULA **lista)
{
    CELULA *atual = *lista;
    CELULA *prox;

    while (atual != NULL)
    {
        prox = atual->next;
        free(atual);
        atual = prox;
    }
}

int main()
{
    int opcao;
    CELULA *lista;
    CELULA *pesquisa;
    PESSOA pessoa;
    inicializarLista(&lista);
    do
    {
        printf("*** MENU PRINCIPAL ***\n");
        printf("[1] -  VERIFICAR SE LISTA ESTA VAZIA\n");
        printf("[2] -  INSERIR PESSOA  NO FIM\n");
        printf("[3] -  INSERIR PESSOA NO INICIO\n");
        printf("[4] -  IMPRIMIR LISTA DE PESSOAS\n");
        printf("[5] -  REMOVER PESSOA NO INICIO\n");
        printf("[6] -  REMOVER PESSOA NO FIM\n");
        printf("[7] -  PESQUISAR POR MATRICULA\n");
        printf("[8] -  REMOVER POR MATRICULA\n");
        printf("[9] -  RETORNAR TAMANHO DA LISTA\n");
        printf("[10] - LIMPAR LISTA\n");
        printf("[0] -  FINALIZAR PROGRAMA\n");
        printf(">>> OPCAO: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            printf("VERIFICAR SE LISTA ESTA VAZIA\n");
            if (listaVazia(&lista))
            {
                printf("Lista Vazia!\n\n");
            }
            else
            {
                printf("Lista não está vazia!\n\n");
            }
            break;
        case 2:
            printf("INSERIR PESSOA  NO FIM\n");
            if (inserirFim(&lista, lerDadosPessoa()))
            {
                printf("Sucesso!\n\n");
            }
            else
            {
                printf("Ocorreu um erro!\n\n");
            }
            break;
        case 3:
            printf("INSERIR PESSOA  NO INICIO\n");
            if (inserirInicio(&lista, lerDadosPessoa()))
            {
                printf("Sucesso!\n\n");
            }
            else
            {
                printf("Ocorreu um erro!\n\n");
            }
            break;
        case 4:
            printf("IMPRIMIR LISTA DE PESSOAS\n");
            imprimirLista(&lista);
            break;
        case 5:
            printf("REMOVER PESSOA NO INICIO\n");
            removerInicio(&lista);
            break;
        case 6:
            printf("REMOVER PESSOA NO FIM\n");
            removerFim(&lista);
            break;
        case 7:
            printf("PESQUISAR POR MATRICULA\n");
            if (listaVazia(&lista))
            {
                printf("Lista Vazia!\n\n");
            }
            else
            {
                pesquisa = pesquisarMatr(&lista, lerMatricula());
                if (pesquisa != NULL)
                {
                    imprimirPessoa(pesquisa->pessoa);
                }
                else
                {
                    printf("Matricula nao encontrada!\n\n");
                }
            }
            break;
        case 8:
            printf("REMOVER POR MATRICULA\n");
            if (listaVazia(&lista))
            {
                printf("Lista Vazia!\n\n");
            }
            else
            {
                pessoa = removeMatr(&lista, lerMatricula());
                if (pessoa.matricula != -1)
                {
                    printf("Pessoa excluida!\n");
                    imprimirPessoa(pessoa);
                    printf("\n");
                }
            }
            break;
        case 9:
            printf("RETORNAR TAMANHO DA LISTA\n");
            printf("Numeros de pessoas cadastradas: %d\n\n", tamanhoLista(&lista));
            break;
        case 10:
            limparLista(&lista);
            printf("Lista limpa!");
        default:
        {
            if (opcao == 0)
            {
                limparLista(&lista);
                printf("Obrigada!");
            }
            else
            {
                printf("Escolha um numero de 1 a 10\n");
            }
            break;
        }
        }

    } while (opcao != 0);

    return 0;
}
