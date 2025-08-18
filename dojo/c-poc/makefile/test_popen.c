#include <stdio.h>
int main() {
    FILE *fp = popen("/home/giovan/c-study/delta 1 -5 6", "r");
    if (!fp) { perror("popen"); return 1; }
    char buf[256];
    if (fgets(buf, sizeof(buf), fp)) printf("Output: %s", buf);
    pclose(fp);
    return 0;
}