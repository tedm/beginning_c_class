#include <stdio.h>
#include <string.h> // For strlen, if you need to remove the newline character
#define MAX_LENGTH 100 // Define a maximum length for your string
int main(int argc, char *argv[]) {
    char user_string[MAX_LENGTH]; // Declare a character array to store the string
    // Prompt the user for input
    printf("Please enter a string: ");
    // Read the string using fgets
    // fgets(buffer, size, stream)
    // buffer: The character array to store the input
    // size: The maximum number of characters to read (including the null terminator)
    // stream: The input stream (stdin for standard input)
    if (fgets(user_string, MAX_LENGTH, stdin) != NULL) {
        // Remove the trailing newline character if present
        // fgets includes the newline if the input fits within the buffer
        size_t len = strlen(user_string);
        if (len > 0 && user_string[len - 1] == '\n') {
            user_string[len - 1] = '\0'; // Replace newline with null terminator
        }
        // Print the entered string
        printf("You entered: %s\n", user_string);
    } else {
        printf("Error reading input.\n");
    }
    return 0;
}
