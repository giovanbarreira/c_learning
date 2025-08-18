/*
16-Faça um programa para uma loja de tintas. 
O programa deverá pedir o tamanho em metros quadrados da área a ser pintada. 
Considere que a cobertura da tinta é de 1 litro para cada 3 metros quadrados e que a tinta é 
vendida em latas de 18 litros, que custam R$ 80,00. Informe ao usuário a quantidades de latas de 
tinta a serem compradas e o preço total.
*/
#include <stdio.h>

int volume_lata = 18;
int cobertura = 3;
int preco_lata = 80;

float area, latas, preco_total;

float calcular_latas(float area) {
    if(area < 0) {
        printf("Área inválida. Deve ser maior que zero.\n");
        return 0;
    }
    float litros_necessarios = area / cobertura;
    float latas_necessarias = litros_necessarios / volume_lata;
    printf("latas necessárias (antes do arredondamento): %.2f\n", latas_necessarias);
    if (latas_necessarias == 0) {
        latas_necessarias = 0;
    }else if((int)latas_necessarias == 0){
        latas_necessarias = 1;
    } else {
        latas_necessarias = (int)(latas_necessarias + 0.9999);
    }

    return (int)latas_necessarias;
}

float calcular_preco(float latas) {
    return latas * preco_lata;
}

int main() {
    
    printf("Digite o tamanho da área a ser pintada em metros quadrados: ");
    scanf("%f", &area);
    
    latas = calcular_latas(area);
    preco_total = calcular_preco(latas);
    
    printf("Quantidade de latas de tinta a serem compradas: %.0f\n", latas);
    printf("Preço total: R$ %.2f\n", preco_total);
    
    return 0;
}