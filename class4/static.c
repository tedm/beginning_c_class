// static.c

#include <stdio.h>
void counter() {
  
    // Static variable retains value between calls
    static int count = 0;  
    count++;
    printf("Count = %d\n", count);
}
int main() {
  
    // Prints: Count = 1
    counter();  
  
    // Prints: Count = 2
    counter(); 
    return 0;
}
