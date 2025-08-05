#include <stdio.h>

int main() {
    char my_char_string[2];
    char ch = 'Z';
        my_char_string[0] = ch;
        my_char_string[1] = '\0';

printf("Character: %c, ASCII  char value: %c\n", ch, ch); // Print char and its ASCII value
printf("Character: %c, ASCII  string value: %s\n", ch, my_char_string); // char and string ASCII value
printf("Character: %c, ASCII  decimal value: %d\n", ch, ch); // char and its ASCII (decimal)
printf("Character: %c, ASCII  octal value: %o\n", ch, ch); // char and its ASCII (octal)
printf("Character: %c, ASCII  hex value: %x\n", ch, ch); // char and its ASCII hex
printf("Character: %c, ASCII  HEX value: %X\n", ch, ch); // char and its ASCII HEX

    return 0;
}
