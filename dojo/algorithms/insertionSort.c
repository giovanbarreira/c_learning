#include <stdio.h>

int main() {
    int A[7] = {0, 5, 2, 4, 6, 1, 3};
    int key = 0;
    int sizeA = sizeof(A) / sizeof(A[0]);

    for (int j = 2; j <= sizeA; j++)
    {                       //2 is 2th
        key = A[j];         //A[2]=2, j=2
        int i = j - 1;      //i=1 and j=2

        while(i > 0 && A[i] > key) { //A[1] = 5 > A[2] = 2
            A[i + 1] = A[i]; //Change A[2] = A[1]
            i = i - 1; //i=1 now is i=0, go back 1 place
            A[i + 1] = key; //A[1] = key = 2, save the key one place to the left
        }
    }

    /*
    // Print sorted array from A[1] to A[6]
    for (int i = 1; i < sizeA; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    */

    printf("%d %d %d %d %d %d \n",A[1],A[2],A[3],A[4],A[5],A[6]);
    return 0;
}