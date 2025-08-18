#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define LOGFILE "log.txt"
#define LOG_CFG "log_cfg.txt"

char LevelChoice = 4; // Default log level

void log_message(int levelChoice, char level, const char *message) {
    int levelValue = 4;
    FILE *fp = fopen(LOGFILE, "a");
    if (!fp) return;
    const char *lvl;
    switch (level) {
        case 'd': lvl = "DEBUG"; levelValue = 5; break;
        case 'i': lvl = "INFO"; levelValue = 4; break;
        case 'w': lvl = "WARN"; levelValue = 3; break;
        case 'e': lvl = "ERROR"; levelValue = 2; break;
        case 'f': lvl = "FATAL"; levelValue = 1; break;
        default: lvl = "INFO";
    }
    if(levelChoice >= levelValue) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        char timestr[20];
        strftime(timestr, sizeof(timestr), "%Y-%m-%d %H:%M:%S", t);
        fprintf(fp, "[%s] %s %s\n", lvl, timestr, message);
    }
    fclose(fp);
}

void read_log_level(char *levelChoice) {
    FILE *fp = fopen(LOG_CFG, "r");
    if (fp) {
        int lvl;
        if (fscanf(fp, "%d", &lvl) == 1) {
            *levelChoice = (char)lvl;

            char msg[100];
            snprintf(msg, sizeof(msg), "Config file log_cfg.txt has level: %d", lvl);
            log_message(LevelChoice, 'i', msg);
        }
        else {            
            *levelChoice = 4; // Default log level if config file was empty or malformed
            log_message(LevelChoice, 'e', "Config file log_cfg.txt was empty or malformed. Using default log level INFO.");
        }
        fclose(fp);
    }
    else {
        *levelChoice = 4; // Default log level if config file not found
        log_message(LevelChoice, 'e', "Config file log_cfg.txt not found. Using default log level INFO.");
    }
}

double delta(double a, double b, double c) {
    double d = b * b - 4 * a * c;
    log_message(LevelChoice, 'd', "Calculated delta");
    return d;
}

double x1(double a, double b, double d) {
    double res = (-b + sqrt(d)) / (2 * a);
    log_message(LevelChoice, 'd', "Calculated x1");
    return res;
}

double x2(double a, double b, double d) {
    double res = (-b - sqrt(d)) / (2 * a);
    log_message(LevelChoice, 'd', "Calculated x2");
    return res;
}

int main() {    
    log_message(LevelChoice, 'i', "App started.");
    read_log_level(&LevelChoice); // Read log level from config
    double a, b, c;
    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);
    printf("Enter c: ");
    scanf("%lf", &c);

    char msg[100];
    snprintf(msg, sizeof(msg), "Input values: a=%.2f, b=%.2f, c=%.2f", a, b, c);
    log_message(LevelChoice, 'd', msg);

    double d = delta(a, b, c);
    printf("Delta: %.2f\n", d);
    snprintf(msg, sizeof(msg), "Delta calculated: %.2f", d);
    log_message(LevelChoice, 'd', msg);

    if (d < 0) {
        printf("No real roots.\n");
        log_message(LevelChoice, 'w', "No real roots");
    } else {
        double root1 = x1(a, b, d);
        double root2 = x2(a, b, d);
        printf("x1: %.2f\n", root1);
        printf("x2: %.2f\n", root2);
        snprintf(msg, sizeof(msg), "Roots: x1=%.2f, x2=%.2f", root1, root2);
        log_message(LevelChoice, 'd', msg);
    }
    log_message(LevelChoice, 'i', "App finished.");
    return 0;
}
