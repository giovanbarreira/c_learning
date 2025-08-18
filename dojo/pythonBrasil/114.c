/*
João Papo-de-Pescador, homem de bem, 
comprou um microcomputador para controlar o rendimento diário de seu trabalho. 
Toda vez que ele traz um peso de peixes maior que o estabelecido pelo 
regulamento de pesca do estado de São Paulo (50 quilos) deve pagar uma multa de R$ 4,00 por quilo excedente. 
João precisa que você faça um programa que leia a variável peso (peso de peixes) e calcule o excesso. 
Gravar na variável excesso a quantidade de quilos além do limite e na variável 
multa o valor da multa que João deverá pagar. Imprima os dados do programa com as mensagens adequadas.
*/
#include <stdio.h>

float peso, excesso, multaTotal;
int pesoMaximo = 50, multa = 4;

int main() {
    printf("Digite o peso dos peixes: ");
    scanf("%f", &peso);

    if (peso > pesoMaximo) {
        excesso = peso - pesoMaximo;
        multaTotal = excesso * multa;
        printf("Peso excedente: %.2f kg\n", excesso);
        printf("Valor da multa: R$ %.2f\n", multaTotal);
    } else {
        printf("Peso dentro do limite, sem multa.\n");
    }

    return 0;
}