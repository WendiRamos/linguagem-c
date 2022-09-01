#include <stdio.h>

int main(void)
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
    return 0;
}