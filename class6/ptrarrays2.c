// ptrarrays2.c

#include <stdio.h>

// Function to traverse 2D array
// using pointers
void traverseArr(int* arr, int N, int M){

    int i, j;

    // Traverse rows of 2D matrix
    for (i = 0; i < N; i++) {

        // Traverse columns of 2D matrix
        for (j = 0; j < M; j++) {

            // Print the element
            printf("%d ", *((arr + i * M) + j));
        }
        printf("\n");
    }
}

int main(){

    int N = 3, M = 2;

    // A 2D array
    int arr[][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };

    // Function Call
    traverseArr((int*)arr, N, M);
    return 0;
}
