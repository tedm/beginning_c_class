// main.c

#include <stdio.h>
#include "person.h"
#include "address.h"

int main() {
    // Declare and initialize a Person struct
    Person p1;
    initializePerson(&p1, "Alice Smith", 30, 1.65);
    printPerson(&p1);

    // Declare and initialize an Address struct
    Address a1 = {"123 Main St", "Anytown", "12345"};
    printAddress(&a1);

    // Struct containing another struct (nested struct concept)
    typedef struct {
        Person resident;
        Address location;
    } Home;

    Home myHome;
    initializePerson(&myHome.resident, "Bob Johnson", 45, 1.80);
    myHome.location = (Address){"456 Oak Ave", "Otherville", "67890"};

    printf("\nHome details:\n");
    printPerson(&myHome.resident);
    printAddress(&myHome.location);

    // Array of structs
    Person employees[2];
    initializePerson(&employees[0], "Charlie Brown", 25, 1.70);
    initializePerson(&employees[1], "Diana Prince", 35, 1.78);

    printf("\nEmployee details:\n");
    for (int i = 0; i < 2; i++) {
        printPerson(&employees[i]);
    }

    return 0;
}
