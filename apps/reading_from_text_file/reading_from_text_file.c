#include <stdio.h>

int main() {
    char name[50];
    int age;
    float height;

    // Open the file for reading
    FILE *file = fopen("data.txt", "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read the data from the file
    fgets(name, sizeof(name), file);
    fscanf(file, "%d", &age);
    fscanf(file, "%f", &height);

    // Close the file
    fclose(file);

    // Print the collected information
    printf("Name: %s", name);
    printf("Age: %d\n", age);
    printf("Height: %.2f cm\n", height);

    return 0;
}

