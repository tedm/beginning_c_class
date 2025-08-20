// add.c 
// we created this program in Class 4 8/19/2025

#include <stdio.h>


int add(int a, int b) { // int is return type, add is function name, (int a, int b) is parameter list
    int sum = a + b;
    return sum; // return_value
} // what is between the { } is the function body

int main() {

	int num1, num2, result;

	printf("Enter 1st number: ");
	scanf("%d", &num1);

	printf("Enter 2nd number: ");
	scanf("%d", &num2);

// call the add function to get the sum

	result = add(num1, num2);

	printf("adding %d and %d is %d\n", num1, num2, result);

	return 0;
}

