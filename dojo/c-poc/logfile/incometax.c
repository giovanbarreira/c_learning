#include <stdio.h>

int main() {
    double inc;
    printf("Enter inc (R$): ");
    scanf("%lf", &inc);
    double rt = 0.0;
    if (inc <= 22847.76) {
        rt = 0.0;
    } else if (inc <= 33919.80) {
        rt = 7.5;
    } else if (inc <= 45012.60) {
        rt = 15.0;
    } else if (inc <= 55976.16) {
        rt = 22.5;
    } else {
        rt = 27.5;
    }
    printf("Your rt is: %.1f%%\n", rt);
    return 0;
}