#include <stdio.h> // Required for printf() and fgets() functions

int main() {
    char name[100]; // Declare a character array (string) to store the name

    // Prompt the user to enter their name
    printf("Enter your name: ");

    // Read the user's input, including spaces, and store it in the 'name' array
    // fgets(variable, size_of_variable, input_stream)
    fgets(name, sizeof(name), stdin);

    // Print the entered name back to the user
    printf("Your name is: %s", name);

    return 0; // Indicate successful program execution
}
