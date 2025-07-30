// compile with -lm flag to link with math library

#include <stdio.h>
#include <math.h>

int main() {
    double principal = 1000; // Initial investment
    double rate = 0.05;      // Annual interest rate
    double time = 10;        // Time in years

    double amount = principal * exp(rate * time);

    printf("Amount after %f years is %f\n", time, amount);
       printf("Amount after %.2f years is rounded %.2f\n", time, amount);
    return 0;
}
