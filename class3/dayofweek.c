// dayofweek.c

#include <stdio.h>

int main() {
  
  	// Day number
    int day = 4;
    
  	// Switch statement to print the name of the day
  	// on the basis of day number
    switch (day) {
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;
    case 7:
        printf("Sunday");
        break;
    default:
        printf("Invalid Input");
        break;
    }
  
    return 0;
}
