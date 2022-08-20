#include <stdio.h>

int main()
{
    float a, b, c, x1, x2, delta;

    printf("Entre o valor para A: ");
    scanf("%f", &a);

    printf("Entre o valor para B: ");
    scanf("%f", &b);

    printf("Entre o valor para C: ");
    scanf("%f", &c);

    delta = (b * b) - 4 * a * c;

    if (delta == 0)
    {
        printf("Existem duas raizes reais e iguais.\n");
        x1 = (-b + sqrt(delta)) / (2 * a);
        printf("X' = X'' = %f.", x1);
    }
    else if (delta < 0)
    {
        printf("Nao existem raizes reais.");
    }
    else
    {
        printf("Existem duas raizes reais e diferentes.\n");
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("X' = %f e X'' = %f.", x1, x2);
    }

    return 0;
}