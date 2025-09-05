#include <stdio.h>
#include <string.h> // For strcpy

// Define a structure for a Book
struct Book {
    char title[100];
    char author[50];
    int publication_year;
};

int main() {
    // Declare a structure variable
    struct Book book1;

    // Assign values to members
    strcpy(book1.title, "The C Programming Language");
    strcpy(book1.author, "Dennis Ritchie");
    book1.publication_year = 1978;

    // Access and print structure members
    printf("Book Title: %s\n", book1.title);
    printf("Author: %s\n", book1.author);
    printf("Publication Year: %d\n", book1.publication_year);

    return 0;
}
