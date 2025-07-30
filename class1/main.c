#include <stdio.h>
#include "my_functions.h" // Include the header file for function declarations

int main() {
    printf("Hello from main!\n");
    print_message(); // Call the function defined in my_functions.c
    return 0;
}

// compile with $gcc main.c my_functions.c -o my_program
