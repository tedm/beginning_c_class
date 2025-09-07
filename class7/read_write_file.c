// read_write_file.c


#include <stdio.h> // Required for standard input/output functions like fopen, fclose, fprintf, fscanf
#include <stdlib.h> // Required for general utilities, including exit()

int main() {
    FILE *fp; // Pointer to a FILE object, used to manage the file stream
    char buffer[100]; // Buffer to store data read from the file
    const char *filename = "example.txt"; // Name of the file to operate on

    // --- Writing to the file ---
    // Open the file in write mode ("w"). If the file doesn't exist, it's created.
    // If it exists, its content is truncated (emptied).
    fp = fopen(filename, "w");
    if (fp == NULL) { // Check if file opening was successful
        perror("Error opening file for writing"); // Print system error message
        exit(EXIT_FAILURE); // Exit with an error code
    }

    fprintf(fp, "This is a line of text.\n"); // Write a string to the file
    fprintf(fp, "Another line with a number: %d\n", 123); // Write a formatted string

    fclose(fp); // Close the file stream, flushing any buffered data
    printf("Data written to %s successfully.\n", filename);

    // --- Reading from the file ---
    // Open the file in read mode ("r"). The file must exist for this to succeed.
    fp = fopen(filename, "r");
    if (fp == NULL) { // Check if file opening was successful
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    printf("\nContent of %s:\n", filename);
    // Read lines from the file until end-of-file (EOF) is reached
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer); // Print the read line to standard output
    }

    fclose(fp); // Close the file stream
    printf("Data read from %s successfully.\n", filename);

    return 0; // Indicate successful execution
}
