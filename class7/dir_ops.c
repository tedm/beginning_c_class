// dir_ops.c

/**
 * dir_ops_linux.c
 *
 * This program demonstrates how to create and remove a directory in a Linux
 * environment using POSIX system calls.
 * 1. It uses mkdir() to create a new directory with specific permissions.
 * 2. It uses rmdir() to remove the newly created directory.
 * 3. It includes error checking for both operations.
 *
 * Compilation: gcc dir_ops_linux.c -o dir_ops_linux
 * Execution:   ./dir_ops_linux
 */

#include <stdio.h>
#include <stdlib.h> // For exit()
#include <sys/stat.h> // For mkdir()
#include <unistd.h>   // For rmdir() and file access checks
#include <errno.h>    // For the errno variable and perror()

// Define the name of the directory we will be working with.
#define DIRNAME "my_new_directory"

int main() {
    // =============================================================
    // PART 1: CREATING A DIRECTORY
    // =============================================================

    printf("Attempting to create directory '%s'...\n", DIRNAME);

    // Use mkdir() to create the directory. The second argument is the mode
    // (file permissions) expressed in octal.
    // 0755 means:
    // - Owner can read, write, and execute (7)
    // - Group members can read and execute (5)
    // - Others can read and execute (5)
    if (mkdir(DIRNAME, 0755) == 0) {
        printf("Directory '%s' created successfully.\n\n", DIRNAME);
    } else {
        // If mkdir() fails, it returns -1.
        // Check for specific error types for better feedback.
        if (errno == EEXIST) {
            printf("Directory '%s' already exists.\n\n", DIRNAME);
        } else {
            fprintf(stderr, "Error: Could not create directory '%s'.\n", DIRNAME);
            perror("Reason");
            exit(EXIT_FAILURE);
        }
    }


    // =============================================================
    // PART 2: REMOVING A DIRECTORY
    // =============================================================

    printf("Attempting to remove directory '%s'...\n", DIRNAME);

    // The rmdir() function removes an empty directory.
    // It will fail if the directory contains any files or subdirectories.
    if (rmdir(DIRNAME) == 0) {
        printf("Directory '%s' removed successfully.\n", DIRNAME);
    } else {
        // rmdir() returns -1 on failure.
        fprintf(stderr, "Error: Could not remove directory '%s'.\n", DIRNAME);
        perror("Reason");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}

