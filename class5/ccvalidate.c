// cc format validation

#include <stdio.h>
#include <string.h>
#include <ctype.h> // For isdigit()

// Function to validate a credit card number using Luhn's algorithm
int isValidLuhn(char cardNumber[]) {
    int nDigits = strlen(cardNumber);
    int sum = 0;
    int isSecondDigit = 0; // Flag to track if it's the second digit from the right

    // Iterate through the digits from right to left
    for (int i = nDigits - 1; i >= 0; i--) {
        if (!isdigit(cardNumber[i])) {
            return 0; // Invalid input if not a digit
        }
        int digit = cardNumber[i] - '0'; // Convert char to int

        if (isSecondDigit) {
            digit *= 2; // Double every second digit
        }

        // Add digits of the doubled number if it's a two-digit number
        sum += digit / 10;
        sum += digit % 10;

        isSecondDigit = !isSecondDigit; // Toggle flag for the next digit
    }

    return (sum % 10 == 0); // Valid if the sum is a multiple of 10
}

int main() {
    char cardNumber[20]; // Assuming max 19 digits + null terminator

    printf("Enter credit card number: ");
    scanf("%s", cardNumber);

    if (isValidLuhn(cardNumber)) {
        printf("The credit card number is VALID.\n");
    } else {
        printf("The credit card number is INVALID.\n");
    }

    return 0;
}

/* explanation:
main() function:
Declares a char array cardNumber to store the input.
Prompts the user to enter the credit card number.
Uses scanf("%s", cardNumber); to read the input.
Calls isValidLuhn() to validate the number and prints the result.

isValidLuhn(char cardNumber[]) function:

Takes a char array representing the credit card number as input.
nDigits stores the length of the number using strlen().

sum accumulates the sum of digits according to the Luhn algorithm.

isSecondDigit is a flag that toggles for every digit processed from right to left, 
ensuring that every second digit is doubled.

The loop iterates from the rightmost digit (nDigits - 1) to the leftmost (0).

isdigit(cardNumber[i]) checks if the character is a digit, returning 0 if not.

cardNumber[i] - '0' converts the character digit to its integer equivalent.

If isSecondDigit is true, the digit is doubled.

sum += digit / 10; and sum += digit % 10; handle the case where doubling results 
in a two-digit number (e.g., 7 doubled is 14, so 1+4=5 is added to the sum).

isSecondDigit = !isSecondDigit; flips the flag for the next iteration.

Finally, return (sum % 10 == 0); checks if the total sum is a multiple of 10, which 
indicates a valid Luhn number.
*/
