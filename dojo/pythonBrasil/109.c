#include <stdio.h>

int main() {
	float fahTemp, celTemp;

	puts("Type the temperature in Fahrenheit:");
	scanf("%f",&fahTemp);

	celTemp = 5 * ((fahTemp-32) / 9);

	printf("The temperature is %.2f .C\r\n", celTemp);

	return 0;
}