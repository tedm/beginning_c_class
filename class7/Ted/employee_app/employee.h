#ifndef EMPLOYEE_H
#define EMPLOYEE_H

// Define a struct for an employee
typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

// Function declarations
void printEmployee(const Employee *emp);
void initializeEmployee(Employee *emp, int id, const char *name, float salary);

#endif // EMPLOYEE_H
