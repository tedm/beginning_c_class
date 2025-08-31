// casttoint.c

#include <stdio.h>
// pointer increment and decrement
// pointers are incremented and decremented 
// by the size of the data type they point to 
int main(){
    int a = 22;
    int *p = &a;
    
    // p = 6422288
    printf("p = %u\n", p); 
    p++;
    // p++ = 6422292    +4 
    // 4 bytes
    printf("p++ = %u\n", p); 
    p--;
    
    // p-- = 6422288     -4    
    // restored to original value
    printf("p-- = %u\n", p); 
    float b = 22.22;
    float *q = &b;
    
    // q = 6422284
    printf("q = %u\n", q);  
    q++;
    
    // q++ = 6422288      +4   
    // 4 bytes
    printf("q++ = %u\n", q); 
    q--;
    
    // q-- = 6422284       -4  
    // restored to original value
    printf("q-- = %u\n", q); 

    char c = 'a';
    char *r = &c;
    
    // r = 6422283
    printf("r = %u\n", r);   
    r++;
    
    // r++ = 6422284     +1   
    // 1 byte
    printf("r++ = %u\n", r);   
    r--;
    
    //r-- = 6422283     -1  
    // restored to original value
    printf("r-- = %u\n", r);   

    return 0;
}
