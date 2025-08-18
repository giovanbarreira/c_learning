/*
13-Tendo como dado de entrada a altura (h) de uma pessoa, construa um algoritmo que 
calcule seu peso ideal, utilizando as seguintes fórmulas:
Para homens: (72.7*h) - 58
Para mulheres: (62.1*h) - 44.7
*/
#include <stdio.h>

char sexo;
float altura, pesoIdeal;

int main() {
    printf("Digite o sexo (M para masculino, F para feminino): ");
    scanf(" %c", &sexo);
    
    printf("Digite a altura em metros: ");
    scanf("%f", &altura);
    
    if (sexo == 'M' || sexo == 'm') {
        pesoIdeal = (72.7 * altura) - 58;
        printf("Peso ideal para homens: %.2f kg\n", pesoIdeal);
    } else if (sexo == 'F' || sexo == 'f') {
        pesoIdeal = (62.1 * altura) - 44.7;
        printf("Peso ideal para mulheres: %.2f kg\n", pesoIdeal);
    } else {
        printf("Sexo inválido!\n");
    }
    
    return 0;
}