// hello.cpp
// compile with g++ hello.cpp -o program
// from Phill @ SCN

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct LinkNode {
    int data;
    LinkNode* next;
};

LinkNode* MakeNode(int info) {
    LinkNode* NewNode = (LinkNode*)malloc(sizeof(LinkNode));
    NewNode->data = info;
    NewNode->next = NULL;
    return NewNode;
}

int main() {
    int arr[] = { 10, 20, 30, 40, 50 };
    int* ptr1 = arr; // ptr1 points to the first element (arr[0])
    printf("Initial value at ptr1: %d\n", *ptr1); // Output: 10
    ptr1++; // Increment ptr1 to point to the next element (arr[1])
    printf("Value at ptr1 after increment: %d\n", *ptr1); // Output: 20
    ptr1 += 2; // Increment ptr1 by 2 elements (points to arr[3])
    printf("Value at ptr1 after adding 2: %d\n", *ptr1); // Output: 40

    printf("-------------------------------------------------\n");

    int* ptr2 = &arr[3]; // ptr2 points to the fourth element (arr[3])
    printf("Initial value at ptr2: %d\n", *ptr2); // Output: 40
    ptr2--; // Decrement ptr2 to point to the previous element (arr[2])
    printf("Value at ptr2 after decrement: %d\n", *ptr2); // Output: 30
    ptr2 -= 2; // Decrement ptr2 by 2 elements (points to arr[0])
    printf("Value at ptr2 after subtracting 2: %d\n", *ptr2); // Output: 10

    printf("-------------------------------------------------\n");

    int* ptr3 = &arr[0]; // ptr3 points to the first element of arr
    printf("Original pointer address: %p\n", (void*)ptr3);
    // Perform pointer arithmetic
    ptr3 = ptr3 + 2; // Move ptr3 two int-sizes forward
    printf("Pointer address after arithmetic: %p\n", (void*)ptr3);
    // Cast the pointer to an integer type for display
    uintptr_t address_as_int = (uintptr_t)ptr3;
    printf("Pointer address as integer: %zu\n", address_as_int);

    printf("-------------------------------------------------\n");

    char first_message[] = "we are safe";
    char second_message[] = "danger danger";
    printf("first address: %p\n", &first_message);
    printf("second address: %p\n", &second_message);
    char* out_of_bounds = &first_message[0];
    out_of_bounds += 0x31;  //might need to fudge this on your system
    printf("first message: %s\n", first_message);
    printf("second message: %s\n", second_message);
    printf("reading second message from first address: %s\n", out_of_bounds);

    printf("-------------------------------------------------\n");

    LinkNode* head = NULL;
    LinkNode* cursor = NULL;
    LinkNode* previous;
    LinkNode array[5]{};

    //load arr into the linked list
    for (int x = 0; x < sizeof(arr) / sizeof(int); x++) {
        
        // make a new node
        LinkNode* NewNode = MakeNode(arr[x]);
        
        // store value in the array
        array[x].data = arr[x];

        // make the new node the first if one does not exist in the list
        if (cursor == NULL) {
            cursor = NewNode;
            head = NewNode;
        }
        
        // add the node to the list and move the cursor
        else {
            cursor->next = NewNode;
            cursor = NewNode;
        }
    }
    
    //reset the cursor
    cursor = head;

    while (cursor != NULL) {
        printf("pointer data: %d\n", cursor->data);
        printf("pointer address: %p\n", cursor);
        cursor = cursor->next;
    }

    // allways free after malloc
    cursor = head;
    while (cursor != NULL)
    {
        previous = cursor;
        cursor = cursor->next;
        free(previous);
    }

    // print array of LinkNodes
    for (int x = 0; x < sizeof(array) / sizeof(LinkNode); x++) {
        printf("array data: %d\n", array[x].data);
        printf("array address: %p\n", &array[x]);
    }

	return 0;
}
