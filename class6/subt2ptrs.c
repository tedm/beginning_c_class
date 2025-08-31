// subt2ptrs.c
// study this program with the subt2ptrsB.c program which uses ptrdiff_t from <stddef.h>


#include <stdio.h>

int main(){
    int x = 6; 
    int N = 4;

    // Pointer declaration
    int *ptr1, *ptr2;
    
    // stores address of N
    ptr1 = &N; 
    
    // stores address of x
    ptr2 = &x; 

    printf(" ptr1 = %u, ptr2 = %u\n", ptr1, ptr2);
    // %p gives an hexa-decimal value,
    // We convert it into an 
    // unsigned int value by using %u

    // Subtraction of ptr2 and ptr1
    x = ptr1 - ptr2;

    // Print x to get the Increment
    // between ptr1 and ptr2
    printf("Subtraction of ptr1 "
           "& ptr2 is %d\n",
           x);

    return 0;
}
