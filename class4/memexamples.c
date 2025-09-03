// memexamples.c

#include <stdio.h>
#include <stdlib.h> // Required for malloc, calloc, realloc, free

int main() {
    int *ptr_malloc = NULL;
    int *ptr_calloc = NULL;
    int *ptr_realloc = NULL;
    int i;

    // 1. malloc(): Allocates a specified number of bytes. The allocated memory is not initialized.
    // Here, we allocate memory for 5 integers.
    printf("--- Using malloc() ---\n");
    ptr_malloc = (int *)malloc(5 * sizeof(int));
    if (ptr_malloc == NULL) {
        printf("Memory allocation with malloc failed!\n");
        return 1; // Indicate an error
    }
    printf("Memory allocated using malloc for 5 integers.\n");
    // Assign values to the allocated memory
    for (i = 0; i < 5; i++) {
        ptr_malloc[i] = i + 1;
        printf("ptr_malloc[%d] = %d\n", i, ptr_malloc[i]);
    }
    printf("\n");

    // 2. calloc(): Allocates a specified number of elements and initializes them to zero.
    // Here, we allocate memory for 5 integers and initialize them to 0.
    printf("--- Using calloc() ---\n");
    ptr_calloc = (int *)calloc(5, sizeof(int));
    if (ptr_calloc == NULL) {
        printf("Memory allocation with calloc failed!\n");
        // Free previously allocated memory before returning
        free(ptr_malloc); 
        return 1; 
    }
    printf("Memory allocated using calloc for 5 integers (initialized to 0).\n");
    // Print values to show they are initialized to 0
    for (i = 0; i < 5; i++) {
        printf("ptr_calloc[%d] = %d\n", i, ptr_calloc[i]);
    }
    printf("\n");

    // 3. realloc(): Resizes a previously allocated memory block.
    // It attempts to extend or shrink the existing block. If not possible, it allocates a new block,
    // copies the old content, and frees the old block.
    // Here, we resize the memory allocated by malloc to hold 10 integers.
    printf("--- Using realloc() ---\n");
    ptr_realloc = (int *)realloc(ptr_malloc, 10 * sizeof(int));
    if (ptr_realloc == NULL) {
        printf("Memory reallocation with realloc failed!\n");
        // Free all allocated memory before returning
        free(ptr_malloc); 
        free(ptr_calloc);
        return 1;
    }
    printf("Memory reallocated using realloc for 10 integers.\n");
    // Note: ptr_malloc is now invalid if realloc moved the block. Use ptr_realloc.
    ptr_malloc = ptr_realloc; 
    // Add values to the newly allocated part
    for (i = 5; i < 10; i++) {
        ptr_malloc[i] = i + 1;
    }
    // Print all 10 values
    for (i = 0; i < 10; i++) {
        printf("ptr_malloc[%d] = %d\n", i, ptr_malloc[i]);
    }
    printf("\n");

    // 4. free(): Deallocates the memory previously allocated by malloc, calloc, or realloc.
    // It is crucial to free dynamically allocated memory to prevent memory leaks.
    printf("--- Using free() ---\n");
    free(ptr_malloc);
    ptr_malloc = NULL; // Good practice to set pointer to NULL after freeing
    printf("Memory allocated by malloc/realloc freed.\n");

    free(ptr_calloc);
    ptr_calloc = NULL;
    printf("Memory allocated by calloc freed.\n");

    return 0; // Indicate successful execution
}

/*

Explanation:

malloc(size_t size):

Allocates size bytes of uninitialized memory. It returns a void* pointer to the beginning
of the allocated block, or NULL if the allocation fails. The returned pointer should be cast
to the desired data type 


calloc(size_t num, size_t size):

Allocates memory for num elements, each of size bytes, and initializes all allocated bytes 
to zero. It returns a void* pointer to the allocated memory, or NULL on failure.


realloc(void *ptr, size_t new_size):

Changes the size of the memory block pointed to by ptr to new_size bytes. The contents of the 
original block are preserved up to the lesser of the new and old sizes. If ptr is NULL, it behaves 
like malloc. If new_size is 0 and ptr is not NULL, it frees the memory. It returns a 
void* pointer to the new memory block (which might be the same as ptr or a new location), 
or NULL if reallocation fails.


free(void *ptr):

Deallocates the memory block pointed to by ptr, which must have been allocated by malloc, calloc, 
or realloc. After free is called, ptr becomes a dangling pointer, so it is good practice to set 
it to NULL. Using a freed pointer leads to undefined behavior.

*/

