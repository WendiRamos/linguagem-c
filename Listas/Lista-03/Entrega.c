#include <stdio.h>
#include <math.h>

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