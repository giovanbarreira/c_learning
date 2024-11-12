#include "division_lib.h"
#include <stdio.h>

int main() {
    double num1, num2, result;

    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    result = divide(num1, num2);

    if (num2 != 0) {
        printf("Result: %.2lf\n", result);
    }

    return 0;
}
