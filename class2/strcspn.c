// program strcspn.c

#include <stdio.h>  // Required for printf and fgets
#include <string.h>  // Required for strlen and strcspn

#define MAX_LENGTH 100 // Define a maximum length for the string

int main() {
    char name[MAX_LENGTH]; // Declare a character array (string) to store the input

    // Prompt the user for input
    printf("Enter your name: ");

    // Read input using fgets()
    // fgets(buffer, size, stream)
    // buffer: The character array to store the input
    // size: The maximum number of characters to read (including the null terminator)
    // stream: The input stream (stdin for standard input)
    if (fgets(name, sizeof(name), stdin) != NULL) {
        // Remove the trailing newline character if present
        // strcspn finds the length of the initial segment of name
        // that consists entirely of characters NOT in the string "\n"
        // This effectively finds the position of the newline character.
        name[strcspn(name, "\n")] = '\0';

        // Print the entered string and its length
        printf("Hello, %s!\n", name);
        printf("Your name has %zu characters (excluding the null terminator).\n", strlen(name));
    } else {
        // Handle potential error during input
        printf("Error reading input.\n");
    }

    return 0; // Indicate successful execution
}
