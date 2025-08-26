// 2darray2.c - prompt for input
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
    	char fruits[3][10];

	for (int i = 0; i < 3; i++) {

		printf("Enter 3 Fruit names:\n");
		scanf("%99s",fruits[i]);
	}
	
    // Printing the array of strings

	for (int i = 0; i < 3; i++) {

    		printf("\nYou entered these fruits: %d : %s\n", i+1 ,fruits[i]);
    	}

    return 0;
}

