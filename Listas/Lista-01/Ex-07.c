#include <stdio.h>

int main()
{
    char caractere;

    printf("Entre um caractere: ");
    scanf("%c", &caractere);

    printf("Caractere %c em decimal: %d \n", caractere, caractere);
    printf("Caractere %c em hexadecimal: %x \n \n", caractere, caractere);
    printf("BRINDE!\n");
    printf("Caractere %c em octal: %o", caractere, caractere);
    return 0;
}

// https://www.freecodecamp.org/portuguese/news/especificadores-de-formatacao-em-c