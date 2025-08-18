#include <math.h>
#include "eq2.h"

double delta(double a, double b, double c) {
    return b * b - 4 * a * c;
}

double x1(double a, double b, double c) {
    double d = delta(a, b, c);
    if (d < 0) return 0.0 / 0.0;
    return (-b + sqrt(d)) / (2 * a);
}

double x2(double a, double b, double c) {
    double d = delta(a, b, c);
    if (d < 0) return 0.0 / 0.0;
    return (-b - sqrt(d)) / (2 * a);
}
