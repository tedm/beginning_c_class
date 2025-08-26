// 2darray.c
// array of strings or a 2D character array, simplay an array of arrays

/* in this case: char fruits[3][10] ...
holds 3 strings, [3] is the first demension.

the 2nd dimension [10] allows each of the first dimension fruits, to be
10 characters, or actually 0 plus 1 for the null terminator \0

We could replace fruits below with:

char name[25][100] and define 25 names, up to 99 characters
*/

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

