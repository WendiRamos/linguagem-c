#include <stdio.h>

int main()
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
    return 0;
}