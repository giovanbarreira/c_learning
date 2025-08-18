#include <stdio.h>

int main() {
    float number;
    int result;

    // Initialize number to an invalid value
    number = -1;

    while (number < 0 || number > 10) {
        printf("Type a number between 0 and 10: ");
        result = scanf("%f", &number);

        // Check if the input is a valid number
        if (result != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            number = -1; // Reset number to force the loop to continue
        }    
    }

    printf("Valid input: %.2f\n", number);
    return 0;
}