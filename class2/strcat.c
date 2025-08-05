//program strcat.c

#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Hello, ";
    char str2[] = "C Programming!";
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);
    return 0;
}
