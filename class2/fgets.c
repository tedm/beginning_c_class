#include <stdio.h>

#define MAX_SIZE 100

int main() {
    char myString[MAX_SIZE];

    printf("Enter a string: ");
    fgets(myString, MAX_SIZE, stdin); // Reads up to MAX_SIZE-1 characters or until a newline, storing it in myString.

    printf("You entered: %s", myString);

    return 0;
}
