// code swapptr.c (simple.c from video here : https://www.youtube.com/watch?v=aeK5FCEHJxU)

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a; //temp = x ; we are dereferencing a
    *a = *b;	//x = y
    *b = temp;	//y = temp, y = x
} 

int main() {
    int x = 37, y = 82;

    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap x = %d, y = %d\n", x, y);

    return 0;

}
