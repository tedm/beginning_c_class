// arrays1.c

#include <stdio.h>

int main() {
    // Declaring and initializing an integer array
    int numbers[5] = {10, 20, 30, 40, 50};

    // Declaring an array and assigning values later
    char grades[3];
    grades[0] = 'A';
    grades[1] = 'B';
    grades[2] = 'C';

    // Printing array elements
    printf("Numbers: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("Grades: ");
    for (int i = 0; i < 3; i++) {
        printf("%c ", grades[i]);
    }
    printf("\n");

    return 0;
}
