#include <stdio.h>

int main() {
	float fahTemp, celTemp;

	puts("Type the temperature in Celsius:");
	scanf("%f",&celTemp);

	fahTemp  = (celTemp / 5 * 9) + 32;

	printf("The temperature is %.2f .F\r\n", fahTemp);

	return 0;
}