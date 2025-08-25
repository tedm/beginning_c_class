// ssvalidate.c

#include <stdio.h>
#include <string.h>
#include <ctype.h> // For isdigit()

int main() {
    char ssn[12]; // 9 digits + 2 hyphens + null terminator

    printf("Enter SSN (XXX-XX-XXXX): ");
    scanf("%11s", ssn); // Read up to 11 characters

    if (strlen(ssn) != 11) {
        printf("Invalid SSN format: Incorrect length.\n");
        return 1;
    }

    // Check for digits and hyphens in correct positions
    if (!isdigit(ssn[0]) || !isdigit(ssn[1]) || !isdigit(ssn[2]) ||
        ssn[3] != '-' ||
        !isdigit(ssn[4]) || !isdigit(ssn[5]) ||
        ssn[6] != '-' ||
        !isdigit(ssn[7]) || !isdigit(ssn[8]) || !isdigit(ssn[9]) || !isdigit(ssn[10])) {
        printf("Invalid SSN format: Contains non-digit or incorrect hyphen placement.\n");
        return 1;
    }

    printf("SSN format is valid.\n");
    return 0;
}
