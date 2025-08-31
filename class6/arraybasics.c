// arraybasics.c

#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr;

    ptr = arr; // 'arr' itself acts as a pointer to the first element

    printf("First element using pointer: %d\n", *ptr);
    printf("Second element using pointer arithmetic: %d\n", *(ptr + 1));
    printf("Third element using array indexing: %d\n", arr[2]);

    // Iterate through the array using a pointer
    printf("Array elements using pointer loop:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    return 0;
}
