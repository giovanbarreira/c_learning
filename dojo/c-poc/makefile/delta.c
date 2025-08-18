#include <stdio.h>
#include <stdlib.h>
#include "eq2.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s a b c\n", argv[0]);
        return 1;
    }
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);
    printf("%f\n", delta(a, b, c));
    return 0;
}
