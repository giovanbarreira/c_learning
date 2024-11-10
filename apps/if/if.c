#include <stdio.h>

int main() {
    float price;

    // Ask for the price
    printf("Enter the price: ");
    scanf("%f", &price);

    // Determine if the price is cheap or expensive
    if (price <= 100) {
        printf("Cheap\n");
    } else {
        printf("Expensive\n");
    }

    return 0;
}

