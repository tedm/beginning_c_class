// malloc5.c

#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

int main() {
    int num_students;
    float *grades; // Pointer to store the grades dynamically

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // Allocate memory for 'num_students' float values
    grades = (float *)malloc(num_students * sizeof(float));

    // Check if malloc was successful
    if (grades == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Indicate an error
    }

    // Input grades for each student
    for (int i = 0; i < num_students; i++) {
        printf("Enter grade for student %d: ", i + 1);
        scanf("%f", &grades[i]);
    }

    // Print the grades
    printf("\nStudent Grades:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Student %d: %.2f\n", i + 1, grades[i]);
    }

    // Free the allocated memory to prevent memory leaks
    free(grades);
    grades = NULL; // Set the pointer to NULL after freeing

    return 0;
}

/* explanation:

Explanation:

#include <stdlib.h>:

This header file is essential as it contains the declarations for malloc and free.

float *grades;:

A pointer grades of type float is declared. This pointer will store the starting address of the
dynamically allocated memory block where the student grades will be stored.

malloc(num_students * sizeof(float)):

sizeof(float) determines the size in bytes required for a single float variable.

This size is multiplied by num_students to calculate the total memory needed for all grades.
malloc attempts to allocate this calculated amount of memory from the heap.

It returns a void pointer to the beginning of the allocated block, or NULL if the allocation fails.

(float *):

The void pointer returned by malloc is explicitly cast to a float * to match the type of the 
grades pointer.

Error Handling (if (grades == NULL)):

It is crucial to check if malloc returned NULL. If it did, it means memory allocation 
failed (e.g., due to insufficient memory), and the program should handle this gracefully.

Accessing Elements:

The allocated memory can be accessed like an array using array-like indexing (e.g., grades[i]).

free(grades);:

After the dynamically allocated memory is no longer needed, it must be deallocated using free(). 
This returns the memory back to the system, preventing memory leaks.

grades = NULL;:

Setting the pointer to NULL after freeing is a good practice to prevent 
"dangling pointers" (pointers that point to deallocated memory).

*/

