#include <stdio.h>

int main() {
    FILE *file;

    // Write 1 to the file
    file = fopen("numbers.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(file, "1\n");
    fclose(file);

    // Write 2 to the file
    file = fopen("numbers.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(file, "2\n");
    fclose(file);

    // Write 3 to the file
    file = fopen("numbers.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(file, "3\n");
    fclose(file);

    printf("Numbers written to numbers.txt\n");

    return 0;
}

