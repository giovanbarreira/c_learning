/*
To compile this program, use:
gcc -o calc calc.c eq2.c -lm

To run the program, use:
./calc
*/
// calc.c

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <mode> <a> <b> <c>\n", argv[0]);
        printf("mode: 0=delta, 1=x1, 2=x2, 3=all\n");
        return 1;
    }
    int mode = atoi(argv[1]);
    char cmd[256];
    const char *execs[] = {"./delta", "./x1", "./x2"};
    if (mode < 0 || mode > 3) {
        printf("Invalid mode. Use 0 for delta, 1 for x1, 2 for x2, 3 for all.\n");
        return 1;
    }
    if (mode == 3) {
        const char *labels[] = {"Delta", "x1", "x2"};
        char result[512];
        memset(result, 0, sizeof(result));
        for (int i = 0; i < 3; ++i) {
            snprintf(cmd, sizeof(cmd), "%s %s %s %s", execs[i], argv[2], argv[3], argv[4]);
            fflush(stdout); // flush output before popen
            FILE *fp = popen(cmd, "r");
            if (!fp) {
                perror("popen");
                return 1;
            }
            printf("About to fgets, cmd: %s\n", cmd);
            fflush(stdout); // flush output before fgets
            char *fgets_ret = fgets(result, sizeof(result), fp);
            if (!fgets_ret) {
                result[0] = '\0';
            }
            printf("fgets returned: %p\n", (void*)fgets_ret);
            if (fgets_ret) {
                printf("%s: %s", labels[i], result);
            } else {
                printf("%s: (no output or error)\n", labels[i]);
            }
            pclose(fp);
        }
    } else {
        snprintf(cmd, sizeof(cmd), "%s %s %s %s", execs[mode], argv[2], argv[3], argv[4]);
        FILE *fp = popen(cmd, "r");
        if (!fp) {
            perror("popen");
            return 1;
        }
        char result[64];
        if (fgets(result, sizeof(result), fp)) {
            printf("Result: %s", result);
        }
        pclose(fp);
    }
    return 0;
}
