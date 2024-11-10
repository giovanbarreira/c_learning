#include <stdio.h>

int main() {
    char name[50];
    int age;
    float height;

    // Ask for the user's name
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    // Ask for the user's age
    printf("Enter your age: ");
    scanf("%d", &age);

    // Ask for the user's height
    printf("Enter your height (in cm): ");
    scanf("%f", &height);

    // Print the collected information
    printf("Name: %s", name);
    printf("Age: %d\n", age);
    printf("Height: %.2f cm\n", height);

    return 0;
}

