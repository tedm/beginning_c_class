// 3darray.c
// from: https://www.geeksforgeeks.org/c/how-to-initialize-a-3d-array-in-c/


// C Program to illustrate how to initialize 3D array
// using initializer list
#include <stdio.h>

int main() {
  
    // Directly initializing 3D array at the time of
    // declaration
    int arr[2][3][2] = { { {0, 1}, {2, 3}, {4, 5} },
                       { {6, 7}, {8, 9}, {10, 11} }};
  	
  	// Printing the array
  	for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }


    return 0;
}
