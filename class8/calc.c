// calc.c compile with debug  info: gcc -g calc.c -o calc

/* after compiling, launch $gdb ./calc, at gdp prompt, set a breakpoint 
with break add then run the program will execute and stop at the beginning 
of the add function

Inspect the variables and step through the code:

print a
print b
next // Execute the current line and move to the next
print sum
next
continue // Continue execution until the next breakpoint or program end

to exit gdb, quit, or ctrl-d

the gdb commands for continue is c, and next is n

watch this youtube video (7m) for basics on gdb: 
https://www.youtube.com/watch?v=OHUFeuBkBuI&t=235s
*/

#include <stdio.h>

int add(int a, int b) {
    int sum = a + b;
    return sum;
}

int main() {
    int x = 10;
    int y = 5;
    int result = add(x, y);
    printf("The sum is: %d\n", result);
    return 0;
}
