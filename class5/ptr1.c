// ptr1.c

#include <stdio.h>

int main() {
	int num  = 42;
	int *ptr = &num;

	printf("Value of num: %d\n", num);
	printf("Address of num: %p\n", &num);
	printf("Value of ptr (Address stored in ptr): %p\n", ptr);
	printf("Value pointed to by ptr: %d\n", *ptr); // dereferencing - getting the value stored at *ptr

	return 0;

}
