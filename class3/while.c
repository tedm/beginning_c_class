/* program while.c

while loop: An entry-controlled loop that executes a block of code as 
long as a given condition remains true. If the condition is false initially, 
the loop body will not execute.

while (condition) {
	// code to be executed repeatedly
}
*/


#include <stdio.h>

int main() {
    int i = 1; // Initialize a counter variable

    // The while loop continues as long as the condition (i <= 5) is true
    while (i <= 5) {
        printf("if you see this, the while (condition) is true, i is %d\n", i); // Print the current value of i
        i++; // Increment i to move towards the loop termination condition
    }

    return 0; // Indicate successful program execution
}
