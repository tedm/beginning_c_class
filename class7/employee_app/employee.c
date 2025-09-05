// employee.c

#include <stdio.h>
#include <string.h>
#include "employee.h" // Include the header file

// Function to print employee details
void printEmployee(const Employee *emp) {
    printf("Employee ID: %d\n", emp->id);
    printf("Employee Name: %s\n", emp->name);
    printf("Employee Salary: %.2f\n", emp->salary);
}

// Function to initialize an employee struct
void initializeEmployee(Employee *emp, int id, const char *name, float salary) {
    emp->id = id;
    strncpy(emp->name, name, sizeof(emp->name) - 1);
    emp->name[sizeof(emp->name) - 1] = '\0'; // Ensure null termination
    emp->salary = salary;
}
