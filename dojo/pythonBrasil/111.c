/*
Faça um Programa que peça 2 números inteiros e um número real. Calcule e mostre:
o produto do dobro do primeiro com metade do segundo .
a soma do triplo do primeiro com o terceiro.
o terceiro elevado ao cubo.
*/
#include<stdio.h>

int n,m;
float r, produto, soma, cubo;

int main() {
    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &n);
    
    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &m);
    
    printf("Digite um numero real: ");
    scanf("%f", &r);
    
    produto = (2 * n) * (m / 2.0);
    soma = (3 * n) + r;
    cubo = r * r * r;
    
    printf("Produto do dobro do primeiro com metade do segundo: %.2f\n", produto);
    printf("Soma do triplo do primeiro com o terceiro: %.2f\n", soma);
    printf("Terceiro elevado ao cubo: %.2f\n", cubo);
    
    return 0;
}