//malloc3.c


#include <stdio.h>  // Required for printf and scanf
#include <stdlib.h> // Required for malloc and free

int main() {
    int n, i, *ptr, sum = 0;

    // Prompt the user to enter the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Allocate memory for 'n' integers using malloc
    // The size of each integer is determined by sizeof(int)
    // The result of malloc is cast to an int pointer
    ptr = (int*) malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (ptr == NULL) {
        printf("Error! Memory not allocated.\n");
        exit(1); // Exit with an error code
    }

    // Prompt the user to enter the elements and calculate their sum
    printf("Enter elements:\n");
    for (i = 0; i < n; ++i) {
        scanf("%d", ptr + i); // Read input into the allocated memory
        sum += *(ptr + i);    // Add the element to the sum
    }

    // Print the calculated sum
    printf("Sum = %d\n", sum);

    // Deallocate the memory previously allocated by malloc
    free(ptr);

    return 0; // Indicate successful execution
}
