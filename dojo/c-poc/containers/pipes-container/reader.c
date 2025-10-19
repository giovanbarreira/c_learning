#include <stdio.h>

int main() {
    int num;
    while (scanf("%d", &num) == 1) {
        printf("Received: %d\n", num);
    }
    return 0;
}

