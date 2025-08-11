// Program goto.c
#include <stdio.h>

int main() {
    int x = 0;
    start:
    x++;
    if (x < 5) {
        goto start; // Jump back to the 'start' label
    }
    printf("x is %d\n", x);

	return 0;
}
