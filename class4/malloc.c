// malloc.c

#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

int main() {
    int *arr;
    int n = 50;

    // Allocate memory for 5 integers
    arr = (int *)malloc(n * sizeof(int));

    // Check if malloc was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Indicate an error
    }

    // Initialize and print the allocated memory
    printf("Malloc example:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);
    arr = NULL; // Set pointer to NULL after freeing to prevent dangling pointer issues

    return 0;
}
