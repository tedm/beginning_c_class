/*
 c99program.c

Note that old c90 standard also doesn't like // for comments!

This will compile with gcc -std=c90 <program.c> -o executablename

note that double slashes for comments wouldn't work in c90 either!

*/


#include <stdio.h>

int main() {

/* Variable declaration within a for loop's initializer (C99 feature)

	int i;

would allow this to compile under -std=c11 or -stdc90
*/

    for (int i = 0; i < 5; i++) {

/* remove the 'int' above to verify it won't compile in C99
*/

        printf("Iteration %d\n", i);
    }

    int x = 10;
    printf("Value of x: %d\n", x);
    int y = 20; 

    printf("Value of y: %d\n", y);

    return 0;
}
