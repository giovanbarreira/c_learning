#include <stdio.h>

int main() {
	float number1, number2, biggest;

	puts("Type a number:");
	scanf("%f",&number1);

	puts("Type a number:");
	scanf("%f",&number2);

    biggest = number2;
	if(number1 > number2) biggest = number1;    

	printf("The biggest number is %.2f\r\n", biggest);

	return 0;
}