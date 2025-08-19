// malloc4.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold student data
struct Student {
    char name[50];
    int age;
};

// Function to create a new student record
struct Student* createStudent(const char* name, int age) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        perror("Error allocating memory for new student");
        exit(EXIT_FAILURE);
    }
    strcpy(newStudent->name, name);
    newStudent->age = age;
    return newStudent;
}

// Function to add a student to the dynamic array
void addStudent(struct Student*** students, int* numStudents, int* capacity, const char* name, int age) {
    // If the array is full, double its capacity
    if (*numStudents == *capacity) {
        *capacity *= 2;
        *students = (struct Student**)realloc(*students, *capacity * sizeof(struct Student*));
        if (*students == NULL) {
            perror("Error reallocating memory for student array");
            exit(EXIT_FAILURE);
        }
        printf("Array capacity increased to %d\n", *capacity);
    }

    // Create a new student record
    struct Student* newStudent = createStudent(name, age);
    (*students)[*numStudents] = newStudent;
    (*numStudents)++;
}

// Function to display all student records
void displayStudents(struct Student** students, int numStudents) {
    if (numStudents == 0) {
        printf("No student records to display.\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d: Name: %s, Age: %d\n", i + 1, students[i]->name, students[i]->age);
    }
    printf("-----------------------\n");
}

// Function to free all allocated memory
void freeStudents(struct Student*** students, int* numStudents) {
    for (int i = 0; i < *numStudents; i++) {
        free((*students)[i]); // Free individual student records
    }
    free(*students); // Free the array of student pointers
    *students = NULL; // Set the pointer to NULL after freeing (good practice)
    *numStudents = 0;
    printf("All student memory freed.\n");
}

int main() {
    struct Student** students = NULL; // Pointer to an array of student pointers
    int numStudents = 0;
    int capacity = 2; // Initial capacity of the dynamic array

    // Allocate initial memory for the array of student pointers
    students = (struct Student**)malloc(capacity * sizeof(struct Student*));
    if (students == NULL) {
        perror("Error allocating initial memory for student array");
        exit(EXIT_FAILURE);
    }
    printf("Initial array capacity: %d\n", capacity);

    // Add some students
    addStudent(&students, &numStudents, &capacity, "Alice", 20);
    addStudent(&students, &numStudents, &capacity, "Bob", 22);
    addStudent(&students, &numStudents, &capacity, "Charlie", 21); // This will trigger a realloc

    displayStudents(students, numStudents);

    // Add another student
    addStudent(&students, &numStudents, &capacity, "David", 23);

    displayStudents(students, numStudents);

    // Free all allocated memory
    freeStudents(&students, &numStudents);

    return 0;
}

