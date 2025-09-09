// structs2.c

#include <stdio.h>

// Define a structure for a point
struct Point {
    int x;
    int y;
};

int main() {
    // Declare and initialize multiple structure variables
    struct Point p1 = {5, 10};
    struct Point p2 = {3, 8};
    struct Point p3 = {7, 12};
    
    // Access and print the values of structure members
    printf("Coordinates of p1: (%d, %d)\n", p1.x, p1.y);
    printf("Coordinates of p2: (%d, %d)\n", p2.x, p2.y);
    printf("Coordinates of p3: (%d, %d)\n", p3.x, p3.y);
    
    return 0;
}

