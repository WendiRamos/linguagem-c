#include <stdio.h>
#include <math.h>

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
    int i;
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

void Ex01()
{
    int *x, *y;
    x = (int *)malloc(sizeof(int));
    y = (int *)malloc(sizeof(int));

    if (x == NULL || y == NULL)
    {
        printf("Nao foi possivel alocar memoria. \n");
        exit(0);
    }

    printf("Entre dois numeros inteiros: ");
    scanf("%d %d", x, y);

    printf("%d\t %d", *x, *y);
    free(x);
    free(y);
    return 0;
}

void Ex02()
{
    int i, num, *x;

    printf("Informe o tamanho do vetor: \n");
    scanf("%d", &num);

    x = (int *)malloc(num * sizeof(int));
    if (x == NULL)
    {
        printf("Nao foi possivel alocar memoria. \n");
        exit(0);
    }

    for (i = 0; i < num; i++)
    {
        printf("Digite o valor para a posicao %d do vetor: ", i + 1);
        scanf("%d", &x[i]);
    }

    printf("\nVetor: \n");
    for (i = 0; i < num; i++)
    {
        printf("%d\n", x[i]);
    }

    free(x);
    return 0;
}

void Ex03()
{
    typedef struct cli
    {
        char nome[20];
        char telefone[12];
        int idade;
    } CLIENTE;

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

void Ex04()
{
    int **matriz, x, y, z;
    int linhas, colunas;

    printf("Entre com o numero de linhas: \n");
    scanf("%d", &linhas);
    printf("Entre com o numero de colunas: \n");
    scanf("%d", &colunas);

    matriz = (int **)malloc(linhas * sizeof(int *));
    for (x = 0; x < linhas; x++)
    {
        matriz[x] = (int *)malloc(colunas * sizeof(int));
    }

    for (x = 0; x < linhas; x++)
    {
        for (y = 0; y < colunas; y++)
        {
            matriz[x][y] = (rand() % 100) + 1;
        }
    }

    for (x = 0; x < linhas; x++)
    {
        for (y = 0; y < colunas; y++)
        {
            printf("%d\t", matriz[x][y]);
        }
        printf("\n");
    }

    for (x = 0; x < linhas; x++)
    {
        free(matriz[x]);
    }
    free(matriz);
    matriz = NULL;
    return 0;
}

void Ex05()
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
    } while (opcao != 0);

    return 0;
}

int main()
{
    int opcao = 0;

    do
    {
        printf("\n    Exercicios\n");
        printf("      MENU     \n");
        printf("1 = Exercicio 1\n");
        printf("2 = Exercicio 2\n");
        printf("3 = Exercicio 3\n");
        printf("4 = Exercicio 4\n");
        printf("5 = Exercicio 5\n");
        printf("0 = Parar\n\n");
        printf("Tecle uma opcao...");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            Ex01();
            break;
        }
        case 2:
        {
            Ex02();
            break;
        }
        case 3:
        {
            Ex03();
            break;
        }
        case 4:
        {
            Ex04();
            break;
        }
        case 5:
        {
            Ex05();
            break;
        }

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
    printf("\n\n\n");
    return 0;
}