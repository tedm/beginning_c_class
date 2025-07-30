#include <stdio.h> // Required for input/output functions like printf
#include <stdbool.h> //C99 and later

int main() {
    // Integer data types
    int integerVar = 100; // Stores whole numbers
    short shortIntVar = 50; // Smaller range integer
    long longIntVar = 1000000000L; // Larger range integer (L suffix for long)
    unsigned int unsignedIntVar = 200; // Stores only non-negative whole numbers

    // Floating-point data types
    float floatVar = 3.14f; // Stores single-precision decimal numbers (f suffix for float)
    double doubleVar = 3.1415926535; // Stores double-precision decimal numbers
    long double longDoubleVar = 3.141592653589793238L; // Stores extended-precision decimal numbers (L suffix for long double)

    // Character data type
    char charVar = 'A'; // Stores a single character

    // Boolean-like behavior (C99 and later, using <stdbool.h>)
    // For older C standards, int 0 for false, non-zero for true is common.
    // #include <stdbool.h>
    bool booleanVar = true;

    // Printing the values and their sizes
    printf("Integer Variable: %d (Size: %zu bytes)\n", integerVar, sizeof(integerVar));
    printf("Short Integer Variable: %hd (Size: %zu bytes)\n", shortIntVar, sizeof(shortIntVar));
    printf("Long Integer Variable: %ld (Size: %zu bytes)\n", longIntVar, sizeof(longIntVar));
    printf("Unsigned Integer Variable: %u (Size: %zu bytes)\n", unsignedIntVar, sizeof(unsignedIntVar));

    printf("Float Variable: %f (Size: %zu bytes)\n", floatVar, sizeof(floatVar));
    printf("Double Variable: %lf (Size: %zu bytes)\n", doubleVar, sizeof(doubleVar));
    printf("Long Double Variable: %Lf (Size: %zu bytes)\n", longDoubleVar, sizeof(longDoubleVar));

    printf("Character Variable: %c (Size: %zu bytes)\n", charVar, sizeof(charVar));
    printf("Boolean Variable: %d (Size: %zu bytes)\n", booleanVar, sizeof(booleanVar)); // Uncomment if using <stdbool.h>

    return 0; // Indicates successful program execution
}
