#include <stdio.h>

int main() {
	float circleRadius, surfaceArea;
    float const pi = 3.14;

	puts("Type the circle radius value (cm):");
	scanf("%f",&circleRadius);

	surfaceArea = pi * circleRadius * circleRadius;

	printf("The circle surface area is %.2f cm2.\r\n", surfaceArea);

	return 0;
}