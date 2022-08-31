#include <stdio.h>

int main (void){
    int numerador, denominador;
    float resultado = 0;
    for (numerador = 1, denominador = 1; numerador < 100; numerador +=2,denominador ++){
        resultado = resultado + (float)numerador / denominador;
    }
    printf("Resultado da soma: %f", resultado);
    return 0;
}