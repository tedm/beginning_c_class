#include <stdio.h>
#include <stdlib.h> // For atoi()

int main(int argc, char **argv) {
    // Print the total number of arguments
    printf("Total arguments: %d\n", argc);

    // Print the program name (argv[0])
    printf("Program name: %s\n", argv[0]);

    // Iterate through and print other arguments
    for (int i = 1; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    // Example of converting a command-line argument to an integer
    if (argc > 1) {
        int number = atoi(argv[1]); // Converts the first argument to an integer
        printf("First argument as integer: %d\n", number);
    }

    return 0;
}
