// Code a c app that ask and read a name and an age, then write the name and the age.
/*
#include <stdio.h>

int main() {
    char name[100];
    int age;

    // Ask for name
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);  // Reads a line including spaces

    // Ask for age
    printf("Enter your age: ");
    scanf("%d", &age);

    // Output the result
    printf("\nHello, %sYou are %d years old.\n", name, age);

    return 0;
}
*/

// Code a c app that ask and read a name and an age, then write the name and the age. Use struct.
/*
#include <stdio.h>

// Define a struct to hold name and age
struct Person {
    char name[100];
    int age;
};

int main() {
    struct Person p;

    // Ask for name
    printf("Enter your name: ");
    fgets(p.name, sizeof(p.name), stdin);  // Reads full line including spaces

    // Ask for age
    printf("Enter your age: ");
    scanf("%d", &p.age);

    // Display the result
    printf("\nHello, %sYou are %d years old.\n", p.name, p.age);

    return 0;
}
*/

// Code a c app that ask 5 int numbers then write those numbers and how many numbers was asked. Use array.
/*
#include <stdio.h>

int main() {
    int numbers[5];
    int sizeA = sizeof(numbers) / sizeof(numbers[0]);

    // Ask the user to input 5 numbers
    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Display the entered numbers
    printf("\nYou entered:\n");
    for (int i = 0; i < 5; i++) {
        printf("Number %d: %d\n", i + 1, numbers[i]);
    }
    printf("Size of the array: %d\n", sizeA);

    return 0;
}
*/