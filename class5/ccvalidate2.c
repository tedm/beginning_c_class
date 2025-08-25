// ccvalidate2.c

#include <stdio.h>
#include <math.h>

int main()
{
    long int cc;
    int digit_count = 0;
    int sum = 0;

    //asks user for input of card number
    do
    {
        printf("Enter card number: ");
        scanf("%ld", &cc);
    }
    while (cc < 1);

    //variables that store the first numbers of the cards
    int amex = cc / pow(10, 13);
    int master = cc / pow(10, 14);
    int visa[2];
    visa[0] = cc / pow(10, 12);
    visa[1] = cc / pow(10, 15);

    //checksum for the luhn algorithm
    while (cc > 0)
    {
        int digit = cc % 10;
        cc /= 10;
        digit_count++;

        if (digit_count % 2 == 0)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;
    }

    //statements to check if cards are valid,american express, visa, mastercard or invalid
    //if the result of sum ends with 0 then this is a valid card from there we check the type of card it is
    if (sum % 10 == 0)
    {
        if (amex == 34 || amex == 37)
        {
            printf("AMEX\n");
        }
        else if (master == 51 || master == 52 || master == 53 || master == 54 || master == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (visa[0] == 4 || visa[1] == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    //terminate the program
    return 0;
}
