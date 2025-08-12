// calcswitch.c

#include <stdio.h>
#include <stdlib.h>

int main() {
    // two number
    int x, y;
  	// Variable that select operation to perform
  	// i.e. switch variable
    char choice;

  	// Take input
    printf("Enter the Operator (+,-,*,/)\n");
    scanf(" %c", &choice);

    printf("Enter the two numbers: ");
    scanf("%d %d", &x, &y);

    // switch case with operation for each operator
    switch (choice) {
    case '+':
        printf("%d + %d = %d\n", x, y, x + y);
        break;

    case '-':
        printf("%d - %d = %d\n", x, y, x - y);
        break;

    case '*':
        printf("%d * %d = %d\n", x, y, x * y);
        break;
    case '/':
        printf("%d / %d = %d\n", x, y, x / y);
        break;
    default:
        printf("Invalid Operator Input\n");
    }
  
    return 0;
}
