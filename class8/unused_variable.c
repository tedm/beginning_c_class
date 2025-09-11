// unused_var.c

#include <stdio.h>

int main(void) {
    // Variable 'x' is declared and initialized, but is never used later in the code.
    // The compiler will issue a warning because this is often a sign of a
    // programmer's mistake or unnecessary code.
    int x = 10;

    printf("Hello, world!\n");

    return 0;
}
