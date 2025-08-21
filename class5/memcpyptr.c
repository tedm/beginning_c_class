// memcpyptr.c

#include <stdio.h> // For printf
#include <string.h> // For memcpy

void swap(void *a, void *b, size_t size) {
    char temp[size]; // Use a VLA or dynamically allocate for larger sizes
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

int main() {
    int x = 10, y = 20;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y, sizeof(int));
    printf("After swap: x = %d, y = %d\n", x, y);

    double d1 = 3.14, d2 = 6.28;
    printf("Before swap: d1 = %f, d2 = %f\n", d1, d2);
    swap(&d1, &d2, sizeof(double));
    printf("After swap: d1 = %f, d2 = %f\n", d1, d2);

    return 0;
}
