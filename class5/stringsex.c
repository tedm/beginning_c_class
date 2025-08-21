// stringsex.c

/*

String Manipulation:
The <string.h> library provides functions for string manipulation:
strlen(str): Returns the length of the string.
strcpy(dest, src): Copies src string to dest.
strcat(dest, src): Concatenates src to dest.
strcmp(str1, str2): Compares two strings.

*/


#include <stdio.h>
#include <string.h> // Required for string functions

int main() {
    char message[20];
    strcpy(message, "Welcome");
    strcat(message, "!");
    printf("%s\n", message); // Output: Welcome!
    return 0;
}
