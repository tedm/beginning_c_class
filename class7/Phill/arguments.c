/*
Basic example of how arguments work.
Compile and run.  Instructions are in the program.

* NOTICE * the first arument [0] is always the command used to run the program.

There is a standard way to parse arguments in C:
https://man7.org/linux/man-pages/man3/getopt.3.html
https://www.geeksforgeeks.org/c/getopt-function-in-c-to-parse-command-line-arguments/
*/


#include <stdio.h>

int main(int argc, char **argv) {
    if (argc == 1)
        printf("This program will help you test command line arguments.\n"
            "Pass arguments by entering the program name then any number of arguments separated by spaces.\n");
    else
        for (int x = 0; x < argc; x++)
            printf("argument %d: %s\n", x, argv[x]);
    return 0;
}
