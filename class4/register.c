// register.c
#include <stdio.h>

int main() {
  
    // Suggest to store in a register
    register int i;  
    for (i = 0; i < 5; i++) {
        printf("%d ", i);
    }
    return 0;
}
