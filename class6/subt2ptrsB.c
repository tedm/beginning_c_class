// subt2ptrsB.c
// contrast this program with subt2ptrs.c which does not use ptrdiff_t from <stddef.h>

#include <stdio.h>
#include <stddef.h> // for ptrdiff_t type

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // ptr points to the first element (arr[0])

    printf("Value at ptr: %d\n", *ptr); // Output: 10

    ptr++; // Increment ptr, now points to arr[1]
    printf("Value at ptr after increment: %d\n", *ptr); // Output: 20

    ptr += 2; // Add 2 to ptr, now points to arr[3]
    printf("Value at ptr after adding 2: %d\n", *ptr); // Output: 40

    int *ptr2 = &arr[0];
    int *ptr3 = &arr[3];
    ptrdiff_t diff = ptr3 - ptr2; // Subtract pointers
    printf("Difference between ptr3 and ptr2: %ld\n", diff); // Output: 3

    return 0;
}

/*

Incrementing/Decrementing a Pointer:

pointer_name++ or ++pointer_name: Advances the pointer to the next element of its pointed-to type.

pointer_name-- or --pointer_name: Moves the pointer to the previous element of its pointed-to type.

The actual memory address change is sizeof(data_type). For example, incrementing an int* pointer 
moves it by sizeof(int) bytes.

Adding/Subtracting an Integer to/from a Pointer:

pointer_name + n: Moves the pointer n elements forward. The address changes by n * sizeof(data_type).

pointer_name - n: Moves the pointer n elements backward. The address changes by n * sizeof(data_type).

Subtracting Two Pointers:

ptr1 - ptr2: This operation is only valid if both pointers point to elements within the same array. 
It yields the number of elements between ptr1 and ptr2. The result is of type ptrdiff_t.

*/

