// args.c

#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Program Name: %s is argv[0]\n", argv[0]);
    printf("Number of arguments: %d\n", argc);

    if (argc > 1) {
        printf("Command-line arguments:\n");
        for (int i = 1; i < argc; i++) {
            printf("argv[%d]: %s\n", i, argv[i]);
        }
    } else {
        printf("No additional command-line arguments provided.\n");
    }

    return 0;
}
