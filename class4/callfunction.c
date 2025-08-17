// callfunction.c

#include <stdio.h>

// Function declaration (prototype)
int add(int a, int b);

int main() {
    int sum = add(5, 3);
    printf("the result of this add function is %d\n", sum);
    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;
}

