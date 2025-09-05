// address.h

#ifndef ADDRESS_H
#define ADDRESS_H

// Define the Address struct
typedef struct {
    char street[100];
    char city[50];
    char zipCode[10];
} Address;

// Function prototype related to Address
void printAddress(const Address *a);

#endif // ADDRESS_H
