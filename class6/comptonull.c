// comptonull.c

#include <stdio.h>

int main(){

    int* ptr = NULL;

    if (ptr == NULL) {
        printf("The pointer is NULL");
    }
    else {
        printf("The pointer is not NULL");
    }
    return 0;
}
