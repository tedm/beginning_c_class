// openwrite.c

#include <stdio.h> // Required for file operations

int main() {
    FILE *filePointer; // Declare a file pointer

    // Open the file "example.txt" in write mode ("w")
    // If "example.txt" doesn't exist, it will be created.
    // If it exists, its content will be overwritten.
    filePointer = fopen("example.txt", "w");

    // Check if the file was opened successfully
    if (filePointer == NULL) {
        printf("Error opening file!\n");
        return 1; // Indicate an error
    }

    printf("File 'example.txt' opened successfully for writing.\n");

    // Close the file
    fclose(filePointer);
    printf("File 'example.txt' closed successfully.\n");

    return 0; // Indicate successful execution
}

/* explanation:

#include <stdio.h>:
This line includes the standard input/output library, which provides 
functions for file handling like fopen(), fclose(), printf(), etc.

FILE *filePointer;:
This declares a pointer of type FILE, which is used to represent the opened file.

fopen("filename.txt", "mode"):
This function attempts to open a file.
The first argument is the name of the file (or its path).
The second argument is the mode in which to open the file: 

"w": Write mode (creates a new file or overwrites an existing one).
"r": Read mode (opens an existing file for reading).

Other modes like "a" (append), "r+" (read and write), "w+" (write and read), etc., 
are also available.

if (filePointer == NULL):
It is crucial to check if fopen() returned NULL, which indicates an error 
(e.g., file not found in read mode, or permissions issue).

fclose(filePointer):
This function closes the opened file, releasing system resources associated with it. 
It is good practice to close files after you are finished with them.
*/