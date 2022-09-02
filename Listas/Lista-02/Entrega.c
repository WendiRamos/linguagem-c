#include <stdio.h>
#include <math.h>

void Ex01()
{
   int contador;
    float numero, numMaior, numMenor;

    for (contador = 0; contador < 12; contador++)
    {
        printf("Entre um numero: \n");
        scanf("%f", &numero);
        if (contador == 0)
        {
            numMaior = numero;
            numMenor = numero;
        }
        else if (numero > numMaior)
        {
            numMaior = numero;
        }
        else if (numero < numMenor)
        {
            numMenor = numero;
        }
    }
    printf("O numero menor: %f\n", numMenor);
    printf("O numero maior: %f", numMaior);
}

void Ex02()
{
    int numerador, denominador;
    float resultado = 0;
    for (numerador = 1, denominador = 1; numerador < 100; numerador +=2,denominador ++){
        resultado = resultado + (float)numerador / denominador;
    }
    printf("Resultado da soma: %f", resultado);
}

void Ex03()
{
   float numero, resultado = 0;
    do
    {
        printf("Entre um numero: \n");
        scanf("%f", &numero);
        resultado = resultado + numero;
    } while (numero != 0);
    
    printf("Resultado da soma dos numeros digitados: %f", resultado);
}

void Ex04()
{
    int contador;

    for (contador = 1000; contador <= 1999; contador++)
    {
        if (contador % 13 == 5)
        {
            printf("%d\t",contador);
        }
    }
}

void Ex05()
{
    int anterior = 0, atual = 1;
    int proximo, quantidade, i;

    printf("Exibir quantos numeros? R: ");
    scanf("%d", &quantidade);

    for (i = 0; i < quantidade; i++){
        printf("%d\t", atual);
        proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }
}

void Ex06()
{
    int resultadoImpar = 0, resultadoPar = 0, i, numero;

    for (i = 0; i < 12; i++)
    {
        do
        {
            printf("Digite o %d numero positivo: ", i+1);
            scanf("%d", &numero);
        } while (numero <= 0);

        if (numero % 2 == 0)
        {
            resultadoPar = resultadoPar + numero;
        }
        else
        {
            resultadoImpar = resultadoImpar + numero;
        }
    }
    printf("Resultado da soma dos numeros pares: %d\n", resultadoPar);
    printf("Resultado da soma dos numeros impares: %d\n", resultadoImpar);
}

void Ex07()
{
   float notas = 0, media, somador = 0;
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("Entre a nota %d: ", i + 1);
        scanf("%f", &notas);
        somador = somador + notas;
    }

    media = somador / 5;
    printf("Media final: %f", media);
}

void Ex08()
{
    int n, valoresEncontrados = 0, i = 1;
    do
    {
        printf("Entre um numero positivo: ");
        scanf("%d", &n);
    } while (n <= 0);

    while (valoresEncontrados < n)
    {
        if (i % 4 == 0 && i % 7 == 0)
        {
            printf("%d\t", i);
            valoresEncontrados++;
        }
        i++;
    }
}

void Ex09()
{
    float josevaldo = 1.35, rafonildo = 1.07;
    int ano = 0;

    while (josevaldo >= rafonildo)
    {
        rafonildo += 0.03;
        josevaldo += 0.02;

        ano++;

        printf("Josevaldo: %.2f\t Rafonildo: %.2f\t Ano: %d\n", josevaldo, rafonildo, ano);
    }
    printf("Sao necessarios %d anos para que Rafonildo fique maior que Josevaldo!", ano);
}

void Ex10()
{
   int a, b, i, resultado = 1;
    
    printf("Entre o numero base: ");
    scanf("%d", &b);

    printf("Entre o numero expoente: ");
    scanf("%d", &a);

    for (i = 0; i < a; i++)
    {
        resultado = resultado * b;
    }
    printf("O valor de %d elevado a %d sera de: %d", a, b, resultado);
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
        printf("6 = Exercicio 6\n");
        printf("7 = Exercicio 7\n");
        printf("8 = Exercicio 8\n");
        printf("9 = Exercicio 9\n");
        printf("10 = Exercicio 10\n");
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
        case 6:
        {
            Ex06();
            break;
        }
        case 7:
        {
            Ex07();
            break;
        }
        case 8:
        {
            Ex08();
            break;
        }
        case 9:
        {
            Ex09();
            break;
        }
        case 10:
        {
            Ex10();
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
                printf("Escolha um numero de 1 a 8\n");
            }
            break;
        }
        }
    } while (opcao != 0);
    printf("\n\n\n");
    return 0;
}