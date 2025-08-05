#include <stdio.h>

int main() {

	int i, j;

	// Outer loop iterates from 1 to 3
	for ( i=1; i <= 3; i++) {
	
		// Inner loop interates from 1 to 3 for each iteration of outer loop
		for (int j=1; j <= 3; j++) {
			printf ("%d\t", i * j); // prints i multipled by j followed by tab
		}
		printf("\n"); // prints new line
	} // closes outer loop
	
	return 0;
}
