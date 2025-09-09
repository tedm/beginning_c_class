// file_ops.c

/**
 * file_ops_stdio.c
 *
 * This program demonstrates fundamental file operations using the standard C
 * library's <stdio.h> functions. It covers:
 * 1. Creating and writing to a new text file.
 * 2. Reading the contents of the file line by line.
 * 3. Closing the file pointers properly.
 * 4. Removing the file from the filesystem.
 *
 * Compilation: gcc file_ops_stdio.c -o file_ops_stdio
 * Execution:   ./file_ops_stdio
 */

#include <stdio.h>
#include <stdlib.h> // For exit()
#include <errno.h>  // For the errno variable and perror()
#include <string.h> // For strcmp()

// Define the name of the file we will be working with.
#define FILENAME "example.txt"

int main() {
    FILE *file_ptr; // A pointer to the FILE object for file handling
    char buffer[256]; // A buffer to store text read from the file

    // =============================================================
    // PART 1: WRITING TO A FILE
    // =============================================================
    
    // Open the file in "write" mode ("w").
    // If the file exists, its contents will be overwritten.
    // If it does not exist, it will be created.
    // Check if fopen() was successful. If not, it returns NULL.
    file_ptr = fopen(FILENAME, "w");
    if (file_ptr == NULL) {
        // Print an error message and exit if the file couldn't be opened.
        fprintf(stderr, "Error: Could not open file for writing.\n");
        perror("Reason"); // perror() prints a descriptive error message based on errno
        exit(EXIT_FAILURE);
    }
    
    printf("Successfully opened '%s' for writing.\n", FILENAME);
    
    // Write some formatted text to the file using fprintf().
    fprintf(file_ptr, "Hello, Linux!\n");
    fprintf(file_ptr, "This is an example of file I/O in C.\n");
    fprintf(file_ptr, "The standard library functions are easy to use.\n");
    
    // Close the file pointer to ensure all data is flushed to disk.
    // It's critical to close files to prevent resource leaks and data corruption.
    fclose(file_ptr);
    printf("Finished writing and closed the file.\n\n");


    // =============================================================
    // PART 2: READING FROM A FILE
    // =============================================================
    
    // Open the file in "read" mode ("r").
    // Check if fopen() was successful.
    file_ptr = fopen(FILENAME, "r");
    if (file_ptr == NULL) {
        fprintf(stderr, "Error: Could not open file for reading.\n");
        perror("Reason");
        exit(EXIT_FAILURE);
    }
    
    printf("Successfully opened '%s' for reading. Contents:\n", FILENAME);
    
    // Read the file line by line until the end of the file (EOF) is reached.
    // fgets() reads a line from the file and stores it in our buffer.
    while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
        // Print the line we just read to the standard output.
        printf("-> %s", buffer);
    }
    
    // Close the file pointer after reading.
    fclose(file_ptr);
    printf("\nFinished reading and closed the file.\n\n");


    // =============================================================
    // PART 3: DELETING A FILE
    // =============================================================
    
    printf("Attempting to delete the file '%s'...\n", FILENAME);
    // The remove() function attempts to delete the specified file.
    // It returns 0 on success and a non-zero value on failure.
    if (remove(FILENAME) == 0) {
        printf("File '%s' deleted successfully.\n", FILENAME);
    } else {
        fprintf(stderr, "Error: Unable to delete the file '%s'.\n", FILENAME);
        perror("Reason");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}

