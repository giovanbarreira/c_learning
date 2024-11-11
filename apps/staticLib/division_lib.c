#include <stdio.h>
#include "division_lib.h"
// Function to perform division
double divide(double numerator, double denominator) {
    if (denominator == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }
    return numerator / denominator;
}
