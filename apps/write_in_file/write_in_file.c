// writing_in_file.c
#include <stdio.h>
int main() {
    // Open the file for writing
    FILE *file = fopen("agreements.txt", "w");
    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    // Write "Hello, World!" to the file
    fprintf(file, "Hello, World!\n");
    // Close the file
    fclose(file);
    printf("Message written to agreements.txt\n");
    return 0;
}
