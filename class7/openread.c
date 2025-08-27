// openread.c

#include <stdio.h> // Required for file operations

int main() {
    FILE *filePointer; // Declare a file pointer

    // Open the file "example.txt" in read mode ("r")
    // If "example.txt" doesn't exist, fopen will return NULL.
    filePointer = fopen("example.txt", "r");

    // Check if the file was opened successfully
    if (filePointer == NULL) {
        printf("Error: File 'example.txt' not found or could not be opened for reading.\n");
        return 1; // Indicate an error
    }

    printf("File 'example.txt' opened successfully for reading.\n");

    // Close the file
    fclose(filePointer);
    printf("File 'example.txt' closed successfully.\n");

    return 0; // Indicate successful execution
}
