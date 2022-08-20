#include <stdio.h>

int main(void)
{
    float valorHora, descontoINSS, salario, salarioLiquido, valorDesconto;
    int horasTrabalhadas;

    printf("Entre o valor pago por hora:R$ \n");
    scanf("%f", &valorHora);

    printf("Entre o numero de horas trabalhadas:R$ \n");
    scanf("%d", &horasTrabalhadas);

    printf("Entre o porcentual de desconto a ser retirado para INSS: \n");
    scanf("%f", &descontoINSS);

    salario = (valorHora * horasTrabalhadas) * 4.5;
    valorDesconto = descontoINSS / 100 * salario;
    salarioLiquido = salario - valorDesconto;
    printf("Salario liquido e:R$ %.2f", salarioLiquido);
    return 0;
}