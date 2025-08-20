//dynstruct.c

// C Program to illustrate how to create a dynamic array
// inside a structure
#include <stdio.h>
#include <stdlib.h>

// Define the structure
typedef struct myStruct {
    int* myArray;
    int size;
} MyStruct;

int main()
{
    // Define the size of the array
    int size = 5;

    // Create a structure variable
    MyStruct s;

    // Create a dynamic array inside the structure
    s.myArray = (int*)malloc(sizeof(int) * size);
    s.size = size;

    // Initialize the array
    for (int i = 0; i < size; i++) {
        s.myArray[i] = i;
    }

    // Print the array elements
    for (int i = 0; i < size; i++) {
        printf("%d ", s.myArray[i]);
    }

    // Delete the dynamic array
    free(s.myArray);

    return 0;
}
