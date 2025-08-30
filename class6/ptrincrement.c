// ptrincrement.c

#include <stdio.h>

int main() {

    int arr[] = {10, 20, 30, 40, 50};

    int *ptr = arr; // ptr points to the first element (arr[0])

    printf("Initial value at ptr: %d\n", *ptr); // Output: 10

    ptr++; // Increment ptr to point to the next element (arr[1])

    printf("Value at ptr after increment: %d\n", *ptr); // Output: 20

    ptr += 2; // Increment ptr by 2 elements (points to arr[3])

    printf("Value at ptr after adding 2: %d\n", *ptr); // Output: 40

    return 0;
}
