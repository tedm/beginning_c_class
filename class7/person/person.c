// person.c

#include <stdio.h>
#include <string.h>
#include "person.h"

void printPerson(const Person *p) {
    printf("Name: %s, Age: %d, Height: %.2f\n", p->name, p->age, p->height);
}

void initializePerson(Person *p, const char *name, int age, float height) {
    strncpy(p->name, name, sizeof(p->name) - 1);
    p->name[sizeof(p->name) - 1] = '\0'; // Ensure null-termination
    p->age = age;
    p->height = height;
}
