#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("How many numbers do you want to sort? ");
    scanf("%d", &n);

    // Allocate memory for n+1 integers (we'll ignore index 0 for CLRS-style)
    int* A = (int*)malloc((n + 1) * sizeof(int));
    if (A == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read numbers into A[1..n]
    for (int i = 1; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &A[i]);
    }

    // Insertion Sort (CLRS-style, starting from index 2)
    for (int j = 2; j <= n; j++) {
        int key = A[j];
        int i = j - 1;

        while (i > 0 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }

    // Print sorted array
    printf("\nSorted numbers:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Free allocated memory
    free(A);
    return 0;
}