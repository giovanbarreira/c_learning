#include <stdio.h>

int main() {
	int firstNumber, secondNumber, sum;
	puts("Type a number:");
	scanf("%d",&firstNumber);
	puts("Type a number:");
	scanf("%d",&secondNumber);
	sum = firstNumber + secondNumber;
	printf("%d + %d = %d\r\n", firstNumber, secondNumber, sum);

	return 0;
}
