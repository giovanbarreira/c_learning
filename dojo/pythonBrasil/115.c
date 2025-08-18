/*
Faça um Programa que pergunte quanto você ganha por hora e o número de horas trabalhadas no mês. 
Calcule e mostre o total do seu salário no referido mês, sabendo-se que são descontados 11% para o Imposto de Renda, 
8% para o INSS e 5% para o sindicato, faça um programa que nos dê:
salário bruto.
quanto pagou ao INSS.
quanto pagou ao sindicato.
o salário líquido.
calcule os descontos e o salário líquido, conforme a tabela abaixo:
+ Salário Bruto : R$
- IR (11%) : R$
- INSS (8%) : R$
- Sindicato ( 5%) : R$
= Salário Liquido : R$
Obs.: Salário Bruto - Descontos = Salário Líquido.
*/
#include <stdio.h>

const float TAXA_IR = 0.11;
const float TAXA_INSS = 0.08;
const float TAXA_SINDICATO = 0.05;

float ganhoPorHora, horasTrabalhadas, salarioBruto, ir, inss, sindicato, salarioLiquido;

/// @brief  Calcula o salário líquido com base no ganho por hora e horas trabalhadas.
/// @details O programa solicita ao usuário o valor ganho por hora e o número de horas trabalhadas no mês. 
///          Em seguida, calcula o salário bruto e os descontos de IR, INSS e sindicato. 
///          Por fim, exibe o salário bruto, os valores descontados e o salário líquido.
/// @note   O cálculo considera as taxas de 11% para IR, 8% para INSS e 5% para o sindicato.
/// @author Nome do Autor
/// @date   2025.07.25
/// @version 1.0
/// @return  0 se o programa for executado com sucesso.
int main() {
    printf("Quanto você ganha por hora? R$ ");
    scanf("%f", &ganhoPorHora);
    printf("Quantas horas trabalhadas no mês? ");
    scanf("%f", &horasTrabalhadas);

    salarioBruto = ganhoPorHora * horasTrabalhadas;

    ir = salarioBruto * TAXA_IR;
    inss = salarioBruto * TAXA_INSS;
    sindicato = salarioBruto * TAXA_SINDICATO;

    salarioLiquido = salarioBruto - (ir + inss + sindicato);

    printf("\n+ Salário Bruto : R$ %.2f\n", salarioBruto);
    printf("- IR (11%%) : R$ %.2f\n", ir);
    printf("- INSS (8%%) : R$ %.2f\n", inss);
    printf("- Sindicato (5%%) : R$ %.2f\n", sindicato);
    printf("= Salário Líquido : R$ %.2f\n", salarioLiquido);

    return 0;
}