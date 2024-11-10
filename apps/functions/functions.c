#include <stdio.h>

// Function to add two numbers
float add(float a, float b) {
    return a + b;
}

// Function to subtract two numbers
float subtract(float a, float b) {
    return a - b;
}

int main() {
    float num1, num2, result;
    char operation;

    // Ask for the first number
    printf("Enter the first number: ");
    scanf("%f", &num1);

    // Ask for the second number
    printf("Enter the second number: ");
    scanf("%f", &num2);

    // Ask for the arithmetic operation
    printf("Enter the operation (+ or -): ");
    scanf(" %c", &operation);

    // Perform the operation using functions
    if (operation == '+') {
        result = add(num1, num2);
    } else if (operation == '-') {
        result = subtract(num1, num2);
    } else {
        printf("Invalid operation!\n");
        return 1;
    }

    // Print the result
    printf("Result: %.2f\n", result);

    return 0;
}

