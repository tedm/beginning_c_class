// Program else-if.c
#include <stdio.h>

int main() {

    int grade = 85;
    if (grade >= 90) {
        printf("A\n");
    } else if (grade >= 80) {
        printf("B\n");
    } else if (grade >= 70) {
        printf("C\n");
    } else {
        printf("Fail\n");
    }
	return 0;
}
