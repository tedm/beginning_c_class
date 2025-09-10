// address.c

#include <stdio.h>
#include "address.h"

void printAddress(const Address *a) {
    printf("Address: %s, %s %s\n", a->street, a->city, a->zipCode);
}
