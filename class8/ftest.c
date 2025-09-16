// ftest.c from: https://www.youtube.com/watch?v=OHUFeuBkBuI&t=235s
// compile with gcc -g ftest.c 
// run gdb list, run, next, b main etc.


#include <stdio.h>

void printMessage(int v) {
	int g = v + 5;
	g = g + 3;
	printf("The value of g is %d\n", g);
}

int main() {

	int a = 0;
	a += 1;
	a += 2;
	a += 3;
	printMessage(a);
	
	return 0;
}
