// compile with gcc <filename.c> -o <executablename> -lm to link math library
#include <stdio.h>
#include <math.h> // Required for the pow() function

int main() {
    double base = 5.0;
    double exponent = 3.0;
    double result;

    result = pow(base, exponent); // Calculates 5 raised to the power of 2

    printf("%.0f raised to the power of %.0f is %.0f\n", base, exponent, result);

    return 0;
}
