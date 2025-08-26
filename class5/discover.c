// discover.c

#include <stdio.h>
#include <string.h>

// Function to validate the card as a Discover card
int is_discover(const char *card_num) {
    int length = strlen(card_num);

    // Check for standard Discover length
    if (length != 16) {
        return 0; // Not a Discover card
    }

    // Check for specific Discover IIN prefixes
    if (strncmp(card_num, "6011", 4) == 0) {
        return 1;
    }
    if (strncmp(card_num, "65", 2) == 0) {
        return 1;
    }

    // Check for the 644-649 range
    if (strncmp(card_num, "64", 2) == 0) {
        // Extract the third digit and check if it's in the 4-9 range
        char third_digit_char = card_num[2];
        if (third_digit_char >= '4' && third_digit_char <= '9') {
            return 1;
        }
    }

    return 0; // Not a Discover card
}

int main(void) {
    char card_number[20];

    printf("Enter a credit card number: ");
    scanf("%s", card_number);

    if (is_discover(card_number)) {
        printf("This is a Discover card.\n");
    } else {
        printf("This is not a Discover card (or is invalid).\n");
    }

    return 0;
}
