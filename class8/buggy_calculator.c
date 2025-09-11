// buggy_calculator.c

#include <stdio.h>

// A function to add two numbers, but with a bug
int add(int a, int b) {
    int sum;
    // GDB Explanation: This line is a good place to set a breakpoint
    // to check the input arguments 'a' and 'b'.
    sum = a + b;
    // The programmer intends to return the sum, but a bug exists here.
    return 0; // BUG: Incorrectly returns 0 instead of the calculated sum.
}

// A function with a loop that has a logical error
void loop_function() {
    int i = 0;
    // GDB Explanation: A watchpoint on 'i' could help detect the infinite loop.
    // Use `watch i` in GDB.
    // A conditional breakpoint `b 20 if i > 5` could also trigger after some iterations.
    while (i <= 10) { // BUG: This should be 'i < 10' for a normal loop.
                      // The current condition causes the loop to run 11 times.
        printf("Loop iteration: %d\n", i);
        i++;
    }
}

int main() {
    // Variable to hold the result of the addition
    int result = 0;
    
    // GDB Explanation: Set a breakpoint here to step into the `add` function
    // to see its behavior. Use `break main` then `run`.
    // Use the `step` command to enter the function call.
    result = add(5, 3);
    
    // GDB Explanation: After the `add` call, print the value of 'result'.
    // `print result` will show the unexpected value of 0.
    printf("Result of addition: %d\n", result); // This will print '0', indicating a bug in `add`.
    
    // GDB Explanation: Set a breakpoint here to observe the loop's behavior.
    // Use the `next` command to step over the `printf` and `loop_function` calls.
    // Use `step` to enter the `loop_function`.
    loop_function();

    // GDB Explanation: Check the call stack after a crash or at a breakpoint.
    // The `backtrace` (or `bt`) command would show the sequence of function calls
    // that led to the current point of execution.
    printf("Program finished.\n");
    return 0;
}

