#include <stdio.h>

int main() {
    int x = 10;
    int y = 1;

    // Logical error: Division by zero
    int result = x / y;

    printf("Result: %d\n", result);

    return 0;
}

