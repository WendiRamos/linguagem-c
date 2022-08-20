#include <stdio.h>

int main()
{
    int v, x;
    float resultado;

    printf("Entre o tempo (minutos): ");
    scanf("%d", &x);

    printf("Entre a velocidade (km/h): ");
    scanf("%d", &v);

    resultado = (x * v) / 60;
    printf("Distancia total percorrida: %.2f km", resultado);

    return 0;
}