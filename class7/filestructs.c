// filestructs.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold contact information
typedef struct {
    char name[50];
    char phone[15];
    char email[50];
} Contact;

#define MAX_CONTACTS 100
#define FILENAME "contacts.dat"

// Function to add a contact to the file
void add_contact() {
    Contact c;
    FILE *fp = fopen(FILENAME, "ab"); // Open file in append binary mode
    if (fp == NULL) {
        perror("Unable to open file");
        return;
    }

    // Get user input
    printf("Enter name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = '\0'; // Remove newline

    printf("Enter phone: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = '\0';

    printf("Enter email: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = '\0';

    // Write the contact to the file
    fwrite(&c, sizeof(Contact), 1, fp);
    fclose(fp);
    printf("Contact saved successfully.\n");
}

// Function to display all contacts from the file
void display_contacts() {
    Contact c;
    FILE *fp = fopen(FILENAME, "rb"); // Open file in read binary mode
    if (fp == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("\n--- Contact List ---\n");
    while (fread(&c, sizeof(Contact), 1, fp)) {
        printf("Name: %s\n", c.name);
        printf("Phone: %s\n", c.phone);
        printf("Email: %s\n\n", c.email);
    }

    fclose(fp);
}

// Main menu loop
int main() {
    int choice;

    while (1) {
        printf("\nContact Manager\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume leftover newline

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_contacts();
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

