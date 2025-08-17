// calloc.c

#include <stdio.h>
#include <stdlib.h> // Required for calloc and free

int main() {
    int *arr;
    int n = 5;

    // Allocate memory for 5 integers and initialize to zero
    arr = (int *)calloc(n, sizeof(int));

    // Check if calloc was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Indicate an error
    }

    // Print the initial zero-initialized values
    printf("Calloc example (initial values):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Modify and print the allocated memory
    printf("Calloc example (modified values):\n");
    for (int i = 0; i < n; i++) {
        arr[i] = i * 5;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);
    arr = NULL;

    return 0;
}
