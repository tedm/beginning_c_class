// scanf.c 

#include <stdio.h>


int main() {

	char myname[20]; // Delcares a character array named myname
  
  	printf("enter your name: \n");
  	scanf("%s", myname);

  	printf("\nyour name is %s\n", myname);

	return 0;
}
