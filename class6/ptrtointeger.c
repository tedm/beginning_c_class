// ptrtointeger.c

#include <stdio.h>
#include <stdint.h> // For uintptr_t

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = &arr[0]; // ptr points to the first element of arr

    printf("Original pointer address: %p\n", (void *)ptr);

    // Perform pointer arithmetic
    ptr = ptr + 2; // Move ptr two int-sizes forward

    printf("Pointer address after arithmetic: %p\n", (void *)ptr);

    // Cast the pointer to an integer type for display
    uintptr_t address_as_int = (uintptr_t)ptr;

    printf("Pointer address as integer: %zu\n", address_as_int);

    return 0;
}
