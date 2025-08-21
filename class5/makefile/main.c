// main.c

#include <stdio.h>
#include "my_functions.h"
#include "another_functions.h"

int main() {
    int sum = add(5, 3);
    printf("Sum: %d\n", sum);

    print_message();

    return 0;
}
