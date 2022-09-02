#include <stdio.h>

int main(void){
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
    return 0;
}