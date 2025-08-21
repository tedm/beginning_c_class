// strings1.c

#include <stdio.h>
#include <string.h> // For string functions like strlen()

int main() {
    // Declaring and initializing a string
    char greeting[] = "Hello, C!"; // Size is automatically determined by the string literal

    // Declaring a string with a specified size
    char name[20];
    strcpy(name, "John Doe"); // Copying a string into the array

    // Printing strings
    printf("Greeting: %s\n", greeting);
    printf("Name: %s\n", name);

    // Finding the length of a string
    printf("Length of greeting: %lu\n", strlen(greeting));

    return 0;
}
