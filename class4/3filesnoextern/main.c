// main.c
// compile with: $gcc my_function.c main.c -o main


#include <stdio.h>
#include "my_function.h" // Include the header file to access greet()

int main() {
    greet(); // Call the function defined in my_function.c
    return 0;
}
