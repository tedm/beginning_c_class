// file_info.c

#include <stdio.h>  // Required for standard input/output functions
#include <sys/stat.h> // Required for stat() function and struct stat
#include <time.h>   // Required for ctime() to format timestamps
#include <stdlib.h> // Required for general utilities, including exit()

int main() {
    struct stat file_stat; // Structure to hold file information
    const char *filename = "example.txt"; // Name of the file to inspect

    // Attempt to get file status. The file must exist.
    if (stat(filename, &file_stat) == -1) { // stat() returns -1 on error
        perror("Error getting file information");
        exit(EXIT_FAILURE);
    }

    printf("File Information for %s:\n", filename);
    printf("  Size: %ld bytes\n", file_stat.st_size); // File size in bytes
    printf("  Permissions: %o\n", file_stat.st_mode & 0777); // File permissions in octal
    printf("  Last Access: %s", ctime(&file_stat.st_atime)); // Last access time
    printf("  Last Modification: %s", ctime(&file_stat.st_mtime)); // Last modification time
    printf("  Last Status Change: %s", ctime(&file_stat.st_ctime)); // Last status change time

    return 0;
}
