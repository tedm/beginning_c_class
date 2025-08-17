// realloc.c

#include <stdio.h>
#include <stdlib.h> // Required for malloc, realloc, and free

int main() {
    int *arr;
    int old_size = 3;
    int new_size = 6;

    // Allocate initial memory for 3 integers
    arr = (int *)malloc(old_size * sizeof(int));
    if (arr == NULL) {
        printf("Initial memory allocation failed!\n");
        return 1;
    }

    // Initialize initial elements
    printf("Realloc example (initial):\n");
    for (int i = 0; i < old_size; i++) {
        arr[i] = i + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reallocate memory to a new size
    int *temp_arr = (int *)realloc(arr, new_size * sizeof(int));

    // Check if realloc was successful
    if (temp_arr == NULL) {
        printf("Memory reallocation failed!\n");
        free(arr); // Free original memory if realloc fails
        return 1;
    }
    arr = temp_arr; // Update the pointer to the potentially new location

    // Initialize new elements and print all elements
    printf("Realloc example (after reallocation):\n");
    for (int i = 0; i < new_size; i++) {
        if (i >= old_size) {
            arr[i] = (i + 1) * 10; // New elements
        }
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the reallocated memory
    free(arr);
    arr = NULL;

    return 0;
}
