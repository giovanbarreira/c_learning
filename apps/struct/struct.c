#include <stdio.h>

// Define a struct to hold the person's information
struct Person {
    char name[50];
    int age;
    float height;
};

int main() {
    struct Person person;

    // Ask for the person's name
    printf("Enter your name: ");
    fgets(person.name, sizeof(person.name), stdin);

    // Ask for the person's age
    printf("Enter your age: ");
    scanf("%d", &person.age);

    // Ask for the person's height
    printf("Enter your height (in cm): ");
    scanf("%f", &person.height);

    // Print the collected information
    printf("Name: %s", person.name);
    printf("Age: %d\n", person.age);
    printf("Height: %.2f cm\n", person.height);

    return 0;
}

