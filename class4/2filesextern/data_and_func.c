// data_and_func.c

#include <stdio.h>

// Define the global variable that main.c will access.
char global_message[] = "Hello from data_and_func.c!";

// Define the function that main.c will call.
void print_message() {
    printf("This message is printed by a function from data_and_func.c.\n");
}
