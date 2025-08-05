// program strcpy.c

#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Copy me!";
    char destination[20]; // Ensure enough space
    strcpy(destination, source);
    printf("Copied string: %s\n", destination);
    return 0;
}
