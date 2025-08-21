// 2darray.c
// array of strings or a 2D character array

#include <stdio.h>

int main() {
    // Declaring and initializing an array of strings
    char fruits[3][10] = {"Apple", "Banana", "Orange"};

    // Printing the array of strings
    printf("Fruits:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\n", fruits[i]);
    }

    return 0;
}
