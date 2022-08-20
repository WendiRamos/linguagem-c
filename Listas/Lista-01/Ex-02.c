#include <stdio.h>

int main(void)
{
    float v, w, x, y, z;
    float pv, pw, px, py, pz;
    float resultado;

    printf("Entre o primeiro numero: ");
    scanf("%f", &v);

    printf("Entre o peso para o primeiro numero: ");
    scanf("%f", &pv);

    printf("Entre o segundo numero: ");
    scanf("%f", &w);

    printf("Entre o peso para o segundo numero: ");
    scanf("%f", &pw);

    printf("Entre o terceiro numero: ");
    scanf("%f", &x);

    printf("Entre o peso para o terceiro numero: ");
    scanf("%f", &px);

    printf("Entre o quarto numero: ");
    scanf("%f", &y);

    printf("Entre o peso para o quarto numero: ");
    scanf("%f", &py);

    printf("Entre o quinto numero: ");
    scanf("%f", &z);

    printf("Entre o peso para o quinto numero: ");
    scanf("%f", &pz);

    resultado = ((v * pv) + (w * pw) + (x * px) + (y * py) + (z * pz)) / (pv + pw + px + py + pz);
    printf("O resultado e: %f ", resultado);
    return 0;
}