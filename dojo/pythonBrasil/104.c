#include <stdio.h>

int main() {
	float score1, score2, score3, score4, average;

	puts("Type a score:");
	scanf("%f",&score1);

	puts("Type a score:");
	scanf("%f",&score2);

	puts("Type a score:");
	scanf("%f",&score3);

	puts("Type a score:");
	scanf("%f",&score4);

	average = (score1 + score2 + score3 + score4) / 4;

	printf("The final score is %.2f\r\n", average);

	return 0;
}