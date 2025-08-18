#include <stdio.h>

int main() {
	float salaryByHour, totalSalary;
    int hourAmount;

	puts("Type the value of the hour:");
	scanf("%f",&salaryByHour);

	puts("Type the amount of hours:");
	scanf("%d",&hourAmount);

	totalSalary = salaryByHour * hourAmount;

	printf("The salary is $%.2f .\r\n", totalSalary);

	return 0;
}