// pointerbasics.c

#include <stdio.h>

int main() {
    int num = 10;
    int *ptr; // Declare a pointer to an integer

    ptr = &num; // Assign the address of 'num' to 'ptr'

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Value of ptr (address it holds): %p\n", ptr);
    printf("Value pointed to by ptr: %d\n", *ptr); // Dereference ptr to get the value

    *ptr = 20; // Change the value of num using the pointer
    printf("New value of num: %d\n", num);

    return 0;
}
