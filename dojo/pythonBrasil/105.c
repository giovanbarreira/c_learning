#include <stdio.h>

int main() {
	int meter, centimeter;

	puts("Type a value (m):");
	scanf("%d",&meter);

	centimeter = meter * 100;

	printf("%d m is %d cm.\r\n", meter, centimeter);

	return 0;
}