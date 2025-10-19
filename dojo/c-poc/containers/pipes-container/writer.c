#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
        fflush(stdout);
        sleep(1);
    }
    return 0;
}

