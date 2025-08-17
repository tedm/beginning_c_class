// main.c

#include <stdio.h>

// Declare 'global_message' as an external variable,
// indicating it is defined in another file.
extern char global_message[]; 

// Declare 'print_message' as an external function,
// indicating it is defined in another file.
extern void print_message();

int main() {
    printf("From main.c: %s\n", global_message); // Access the external variable
    print_message(); // Call the external function
    return 0;
}
