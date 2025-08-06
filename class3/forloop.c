/* program forloop.c


    for (initialization; condition; update) {
        // code to be executed repeatedly
    }


for loop: An entry-controlled loop ideal for situations where the 
number of iterations is known in advance. It includes initialization, 
condition checking, and update expressions within its structure.
*/


#include <stdio.h>

int main() {

	for (int i =1; i <=10; i++)  	{
		printf("hello, i is %d\n", i);
	}

	return 0;
}
