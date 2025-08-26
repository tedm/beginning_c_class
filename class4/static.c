// static.c

// note that in line if line 16, the int count has static in front. 
// static retains the value between function calls, during the
// lifetime of the program execution, 
// 
// unlike auto whose value gets reset upon each call, and whose scope and lifetime are only
// within the block/function. Without static here, count=0 would get reset each time counter()
// is called

#include <stdio.h>

void counter() {
  
    // Static variable retains value between calls
    static int count = 0;  // without static, count would re-initialize to 0 each time counter()
    // is called in main() below
    count++;
    printf("Count = %d\n", count);
}
int main() {
  
    // Prints: Count = 1 
        counter();  
    // if static were removed from int count = 0, then count would reset each time, counter() would 
    // return all 1's
        counter(); // 2
        counter(); // 3
        counter(); // 4
        counter(); // 5
    return 0;
}
