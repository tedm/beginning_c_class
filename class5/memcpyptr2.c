// memcpyptr2.c

// note: memcpy() which is declared in the string.h header has the following prototype:
// void *memcpy(void *dest, const void *src, size_t n);


#include <stdio.h>
#include <string.h> // For memcpy()

// A generic swap function using void pointers and memcpy
void swap_generic(void *a, void *b, size_t size) {
    if (a == b) { // Handle the case where the pointers are the same
        return;
    }
    unsigned char temp[size]; // Create a temporary buffer
    memcpy(temp, a, size);     // Copy data from 'a' to temp
    memcpy(a, b, size);       // Copy data from 'b' to 'a'
    memcpy(b, temp, size);    // Copy data from temp to 'b'
}

int main() {
    int x = 10, y = 20;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap_generic(&x, &y, sizeof(int)); // Swap integers
    printf("After swap: x = %d, y = %d\n", x, y);

    float f1 = 3.14, f2 = 6.28;
    printf("Before swap: f1 = %.2f, f2 = %.2f\n", f1, f2);
    swap_generic(&f1, &f2, sizeof(float)); // Swap floats
    printf("After swap: f1 = %.2f, f2 = %.2f\n", f1, f2);

    return 0;
}

