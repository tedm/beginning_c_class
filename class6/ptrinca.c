// ptrinca.c

#include <stdio.h>

int main() {
    int arr[3] = {10, 20, 30};
    int *p = arr;

    printf("First element: %d\n", *p);       // 10
    p++;                                     // Move to next int (4 bytes ahead)
    printf("Second element: %d\n", *p);      // 20
    p++;
    printf("Third element: %d\n", *p);       // 30

    return 0;
}

