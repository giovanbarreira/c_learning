/*
12-Tendo como dados de entrada a altura de uma pessoa, 
construa um algoritmo que calcule seu peso ideal, usando a seguinte fórmula: (72.7*altura) - 58
*/
#include<stdio.h>

float altura, pesoIdeal;

int main() {
    printf("Digite a altura da pessoa (em metros): ");
    scanf("%f", &altura);
    
    pesoIdeal = (72.7 * altura) - 58;
    
    printf("O peso ideal para uma altura de %.2f metros é: %.2f kg\n", altura, pesoIdeal);
    
    return 0;
}