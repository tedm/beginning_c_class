// dynamicmemallocation.c
// When the sizte of a string is unknown at compile time, pointers
// and dynamic memory allocation (e.g. malloc) are used

    #include <stdio.h>
    #include <stdlib.h> // For malloc, free
    #include <string.h>

    int main() {
        char *dynamic_str;
        int size = 50;

        dynamic_str = (char *)malloc(size * sizeof(char));
        if (dynamic_str == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        strcpy(dynamic_str, "Dynamically allocated string.");
        printf("%s\n", dynamic_str);

        free(dynamic_str); // Release allocated memory
        return 0;
    }
