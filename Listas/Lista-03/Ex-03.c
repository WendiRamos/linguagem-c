#include <stdio.h>
#include <stdlib.h>

typedef struct cli
{
    char nome[20];
    char telefone[12];
    int idade;
} CLIENTE;

int main()
{
    int i, num;
    CLIENTE *c;

    printf("Quantos clientes deseja cadastrar? \n");
    scanf("%d", &num);

    c = (CLIENTE *)malloc(num * sizeof(CLIENTE));
    if (c == NULL)
    {
        printf("Nao foi possivel alocar memoria. \n");
        exit(0);
    }

    for (i = 0; i < num; i++)
    {
        printf("\nDigite o nome para o cadastro de posicao %d: ", i + 1);
        scanf("%s", c[i].nome);

        printf("\nDigite o telefone para o cadastro de posicao %d: ", i + 1);
        scanf("%s", c[i].telefone);

        printf("\nDigite a idade para o cadastro de posicao %d: ", i + 1);
        scanf("%d", &c[i].idade);
    }
    printf("\n");
    for (i = 0; i < num; i++)
    {
        printf("%s\n", c[i].nome);
        printf("%s\n", c[i].telefone);
        printf("%d\n", c[i].idade);
    }

    free(c);
    return 0;
}