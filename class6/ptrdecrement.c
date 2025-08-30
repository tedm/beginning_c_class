// ptrdecrement.c

#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = &arr[3]; // ptr points to the fourth element (arr[3])

    printf("Initial value at ptr: %d\n", *ptr); // Output: 40

    ptr--; // Decrement ptr to point to the previous element (arr[2])
    printf("Value at ptr after decrement: %d\n", *ptr); // Output: 30

    ptr -= 2; // Decrement ptr by 2 elements (points to arr[0])
    printf("Value at ptr after subtracting 2: %d\n", *ptr); // Output: 10

    return 0;
}
