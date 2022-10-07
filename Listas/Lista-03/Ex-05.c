#include <stdio.h>
#include <stdlib.h>
int i;
typedef struct sCarros
{
    char placa[15];
    char cor[15];
    int ano;
} Carro;

void cadastrar(Carro *pCar, int contCar)
{
    printf("------------ Cadastrar Carro ----------\n");
    printf("Entre com as informacoes do novo carro:\n");

    printf("Placa: ");
    scanf("%s", pCar[contCar].placa);

    printf("Cor: ");
    scanf("%s", pCar[contCar].cor);

    printf("Ano: ");
    scanf("%d", &pCar[contCar].ano);
}

void editar(Carro *pCar, int contCar)
{ 
    int i;
    char placa[15], posicao = -1;
    printf("======================= EDITAR ======================\n");
    printf("Entre com a placa do veiculo a ser editado: ");
    scanf(" %[^\n]", placa);
    for ( i = 0; i < contCar; i++)
    {
        if (strcmp(pCar[i].placa, placa) == 0)
        {
            posicao = i;
            break;
        }
    }
    if (posicao == -1)
    {
        printf("Nao encontrado :(\n");
    }
    else
    {
        printf("===================== VEICULO %d =====================\n", posicao + 1);
        printf("| PLACA: %s\n", pCar[posicao].placa);
        printf("| COR:   %s\n", pCar[posicao].cor);
        printf("| ANO:   %d\n", pCar[posicao].ano);
        printf("======================================================\n\n");

        int opcaoEditar = 0;

        printf("======================== MENU ========================\n");
        printf("| 1 ........................................... PLACA |\n");
        printf("| 2 ............................................. COR |\n");
        printf("| 3 ............................................. ANO |\n");
        printf("| Outro .................................... CANCELAR |\n");
        printf("======================================================\n");
        scanf("%d", &opcaoEditar);

        switch (opcaoEditar)
        {
        case 1:
            printf("PLACA: ");
            scanf("%s", pCar[posicao].placa);
            break;
        case 2:
            printf("COR: ");
            scanf("%s", pCar[posicao].cor);
            break;
        case 3:
            printf("ANO: ");
            scanf("%d", &pCar[posicao].ano);
            break;
        }
    }
}

void listar(Carro *pCar, int contCar)
{
    if (contCar == 0)
    {
        printf("Nenhum carro cadastrado :(\n");
    }
    else
    {
        printf("======================= LISTAR ======================\n");
        for ( i = 0; i < contCar; i++)
        {
            printf("===================== VEICULO %d =====================\n", i + 1);
            printf("| PLACA: %s\n", pCar[i].placa);
            printf("| COR:   %s\n", pCar[i].cor);
            printf("| ANO:   %d\n", pCar[i].ano);
            printf("======================================================\n\n");
        }
    }
}

int main(void)
{
    int n = 0, opcao;
    Carro carros[100];

    do
    {
        printf("Digite a opcao desejada: \n");
        printf("1 - Cadastrar\n");
        printf("2 - Editar\n");
        printf("3 - Listar\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrar(&carros, n);
            n++;
            break;
        case 2:
            editar(&carros, n);
            break;
        case 3:
            listar(&carros, n);
            break;
        }
    }
    while (opcao != 0);

    return 0;
}