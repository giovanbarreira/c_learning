#include <stdio.h>

int main() {
	float squareSideValue, surfaceArea, surfaceAreaDouble;
    float const pi = 3.14;

	puts("Type the square side value (cm):");
	scanf("%f",&squareSideValue);

	surfaceArea = squareSideValue * squareSideValue;
    surfaceAreaDouble = 2 * surfaceArea;

	printf("The double of the surface area is %.2f cm2.\r\n", surfaceAreaDouble);

	return 0;
}