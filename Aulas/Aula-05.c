#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Errado
    int a = 5;
    int *p = NULL;
    *p = a;

    // Errado
    int a = 5;
    int *p = NULL;
    *p = &a;

    // Certo
    int a = 5;
    int *p = NULL;
    p = &a;

    // Certo
    int *p;
    p = (int *)malloc(sizeof(int));
    *p = 5;
}
