// program strlen.c

#include <stdio.h>
#include <string.h>

int main() {
    char myString[] = "Hello, World!";
    int length = strlen(myString);
    printf("Length of the string: %d\n", length);
    return 0;
}
