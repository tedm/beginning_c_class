// stringcopy.c

    #include <stdio.h>
    #include <string.h> // For strcpy

    int main() {
        char source[] = "Copy me!";
        char destination[20]; // Ensure enough space

        strcpy(destination, source); // Using library function
        printf("Copied string: %s\n", destination);

        // Manual copy using pointers
        char *src_ptr = source;
        char *dest_ptr = destination;
        while ((*dest_ptr++ = *src_ptr++) != '\0');
        printf("Manually copied string: %s\n", destination);
        return 0;
    }
