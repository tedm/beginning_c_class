// malloc2.c

#include <stdio.h>
#include <stdlib.h> // for malloc and free

int main() {
    int *myNumberPtr; // Declare a pointer to an integer

    // Rent enough space for one integer from the heap
    myNumberPtr = (int *)malloc(sizeof(int)); 

    if (myNumberPtr == NULL) { // Always check if malloc succeeded
        printf("Memory allocation failed!\n");
        return 1; 
    }

    *myNumberPtr = 42; // Store the value 42 in the rented mailbox

    printf("Value: %d\n", *myNumberPtr); // Retrieve and print the value

    free(myNumberPtr); // Return the mailbox to the post office
    myNumberPtr = NULL; // Set the pointer to NULL after freeing (good practice)

    return 0;
}
