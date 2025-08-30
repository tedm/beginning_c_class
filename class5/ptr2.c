// ptr2.c - allows user input

#include <stdio.h>

int main() {
	static int num = 5;
	int *ptr = &num;

	printf("enter an integer: ");
	scanf("%d", &num);

	printf("Value of num: %d\n", num);
	printf("Address of num: %p\n", &num);
	printf("Value of ptr (Address stored in ptr): %p\n", ptr);
	printf("Value pointed to by ptr: %d\n", *ptr); // dereferencing - getting the value stored at *ptr

	return 0;

}
