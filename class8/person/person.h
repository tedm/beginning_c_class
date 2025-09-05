// person.h

#ifndef PERSON_H
#define PERSON_H

// Define the Person struct
typedef struct {
    char name[50];
    int age;
    float height;
} Person;

// Function prototypes related to Person
void printPerson(const Person *p);
void initializePerson(Person *p, const char *name, int age, float height);

#endif // PERSON_H
