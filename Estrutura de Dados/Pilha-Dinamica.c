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

void inicializarPilha(CELULA **pilha)
{
    (*pilha) = NULL;
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

int pilhaVazia(CELULA **pilha)
{
    if (*pilha == NULL)
    {
        return 1;
    }
    return 0;
}

int push(CELULA **pilha, PESSOA pessoa)
{
    CELULA *celula = novaCelula(pessoa);
    if (celula == NULL)
    {
        return 0;
    }

    celula->next = *pilha;
    *pilha = celula;
    return 1;
}

PESSOA pop(CELULA **pilha)
{
    CELULA *celulaRemovida;
    PESSOA pessoaRemovida;

    strcpy(pessoaRemovida.nome, " ");
    pessoaRemovida.matricula = -1;

    if (pilhaVazia(pilha))
    {
        printf("Pilha Vazia!\n\n");
        return pessoaRemovida;
    }

    celulaRemovida = *pilha;
    pessoaRemovida = celulaRemovida->pessoa;

    *pilha = (*pilha)->next;

    free(celulaRemovida);
    return pessoaRemovida;
}

PESSOA lerDadosPessoa()
{
    char nome[50];
    int matricula;
    printf("Entre com os dados da pessoa:\n");
    printf("NOME: ");
    scanf(" %[^\n]s", nome);
    do
    {
        printf("MATRICULA: ");
        scanf("%d", &matricula);
    } while (matricula <= 0);
    return criarPessoa(nome, matricula);
}

void imprimirPessoa(PESSOA pessoa)
{
    printf("MATRICULA: %5d\t NOME: %s\n", pessoa.matricula, pessoa.nome);
}

int imprimirEsvaziarPilha(CELULA **pilha)
{
    PESSOA pessoa;
    if (pilhaVazia(pilha))
    {
        printf("Pilha Vazia!\n\n");
        return 0;
    }
    while (!pilhaVazia(pilha))
    {
        pessoa = pop(pilha);
        if (pessoa.matricula != -1)
        {
            imprimirPessoa(pessoa);
        }
    }
    return 1;
}

int acessarTopo(CELULA **pilha)
{
    PESSOA pessoa;
    if (pilhaVazia(pilha))
    {
        printf("Pilha Vazia!\n\n");
        return 0;
    }

    pessoa = pop(pilha);
    imprimirPessoa(pessoa);
    push(pilha, pessoa);
    return 1;
}

int main()
{
    int opcao;
    CELULA *pilha;
    PESSOA pessoa;
    inicializarPilha(&pilha);
    do
    {
        printf("*** MENU PRINCIPAL ***\n");
        printf("[1] - VERIFICAR SE PILHA ESTA VAZIA\n");
        printf("[2] - PUSH\n");
        printf("[3] - POP\n");
        printf("[4] - IMPRIMIR E ESVAZIAR PILHA\n");
        printf("[5] - ACESSAR TOPO SEM REMOVER\n");
        printf("[0] - FINALIZAR PROGRAMA\n");
        printf(">>> OPCAO: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            printf("VERIFICAR SE PILHA ESTA VAZIA\n");
            if (pilhaVazia(&pilha))
            {
                printf("Pilha Vazia!\n\n");
            }
            else
            {
                printf("Pilha não está vazia!\n\n");
            }
            break;
        case 2:
            printf("PUSH\n");
            push(&pilha, lerDadosPessoa());
            break;
        case 3:
            printf("POP\n");
            pop(&pilha);
            break;
        case 4:
            printf("IMPRIMIR E ESVAZIAR PILHA\n");
            imprimirEsvaziarPilha(&pilha);
            break;
        case 5:
            printf("ACESSAR TOPO SEM REMOVER\n");
            acessarTopo(&pilha);
            break;
        default:
        {
            if (opcao == 0)
            {
                printf("Obrigada!");
            }
            else
            {
                printf("Escolha um numero de 1 a 5\n");
            }
            break;
        }
        }

    } while (opcao != 0);

    return 0;
}
