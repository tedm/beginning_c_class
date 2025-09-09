// main.c

/* compile with:

gcc -c employee.c -o employee.o
gcc -c main.c -o main.o
gcc employee.o main.o -o employee_app
*/


#include <stdio.h>
#include <string.h>
#include "employee.h" // Include the header file


int main() {
    // Declare an Employee struct variable
    Employee emp1;

    // Initialize the employee using the function
    initializeEmployee(&emp1, 101, "Alice Smith", 65000.00);

    // Print employee details using the function
    printf("--- Employee 1 Details ---\n");
    printEmployee(&emp1);

    // Demonstrate nested structs (anonymous struct for address)
    struct {
        char street[100];
        char city[50];
    } address;

    strncpy(address.street, "123 Main St", sizeof(address.street) - 1);
    address.street[sizeof(address.street) - 1] = '\0';
    strncpy(address.city, "Anytown", sizeof(address.city) - 1);
    address.city[sizeof(address.city) - 1] = '\0';

    printf("\nEmployee 1 Address: %s, %s\n", address.street, address.city);

    return 0;
}
