// ptrfunctions.c

#include <stdio.h>

// A simple function
void greet() {
    printf("Hello from the function!\n");
}

// A function that takes two integers and returns their sum
int add(int a, int b) {
    return a + b;
}

int main() {
    void (*greet_ptr)(); // Declare a function pointer for 'greet'
    int (*add_ptr)(int, int); // Declare a function pointer for 'add'

    greet_ptr = &greet; // Assign the address of 'greet' to 'greet_ptr'
    add_ptr = &add; // Assign the address of 'add' to 'add_ptr'

    greet_ptr(); // Call 'greet' using the function pointer

    int sum = add_ptr(5, 7); // Call 'add' using the function pointer
    printf("Sum of 5 and 7: %d\n", sum);

    return 0;
}
