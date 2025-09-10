#include "fileops.h"
#include "ingredients.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int passed_error_checks = 0;

//generic failure program end
void Failure(FILE *file_pointer) {
    printf("program failed\n");
    if (file_pointer != NULL) fclose(file_pointer);
    exit(EXIT_FAILURE);
}

//means of checking for file pointer errors
void CheckErrorFile(FILE *file_pointer) {

    //shut down the program if something bad happens
    if (file_pointer == NULL || ferror(file_pointer) != 0) {
        printf("file pointer address: %p\n", file_pointer);
        printf("Error number: %d\n", errno);
        perror("perror");
        printf("strerror: %s\n", strerror(errno));
        Failure(file_pointer);
    }

    //success counter
    passed_error_checks++;
}

//error checking using errno
void CheckErrorClosed() {
    
    //shut down the program if something bad happens
    if (errno != 0) {
        printf("Error number: %d\n", errno);
        perror("perror");
        printf("strerror: %s\n", strerror(errno));
        Failure(NULL);
    }
    
    //success counter
    passed_error_checks++;
}

void WriteInventory(int *ram_inventory, int size) {
    if (size != INGREDIENT_LIST_SIZE) {
        printf("ingrediant array is not the right size.\n"
            "expected [%d] found [%d]\n",
            INGREDIENT_LIST_SIZE, size);
        Failure(NULL);
    }

    FILE *file_pointer = fopen(INVENTORY_FILE_NAME, "wb");
    CheckErrorFile(file_pointer);

    fwrite(ram_inventory, sizeof(int), size, file_pointer);
    CheckErrorFile(file_pointer);

    fclose(file_pointer);
    CheckErrorClosed();
}

void ReadInventory(int *ram_inventory, int size) {
    if (size != INGREDIENT_LIST_SIZE) {
        printf("ingrediant array is not the right size.\n"
            "expected [%d] found [%d]\n",
            INGREDIENT_LIST_SIZE, size);
        Failure(NULL);
    }
    
    FILE *file_pointer = fopen(INVENTORY_FILE_NAME, "rb");
    //special catch to create new file
    if (errno == 2 && file_pointer == NULL) return;
    CheckErrorFile(file_pointer);

    size = fread(ram_inventory, sizeof(int), INGREDIENT_LIST_SIZE, file_pointer);
    CheckErrorFile(file_pointer);

    if (size != INGREDIENT_LIST_SIZE) {
        printf("Wrong number of ingredients in file.\n"
            "expected [%d] found [%d]\n",
            INGREDIENT_LIST_SIZE, size);
        Failure(NULL);
    }

    fclose(file_pointer);
    CheckErrorClosed();
}

void WriteOrder(customer_order *order) {
    
    //check for null
    if (order == NULL) {
        printf("order was null\n");
        Failure(NULL);
    }

    //open file
    FILE *file_pointer = fopen(ORDERS_FILE_NAME, "a");
    CheckErrorFile(file_pointer);

    //write file
    int added = fprintf(file_pointer, ORDER_PATERN,
        order->order_time, order->name, order->toppings);
    
    //make sure line was added
    if (added < 1) {
        printf("order was not added %d\n", added);
        CheckErrorFile(file_pointer);
        Failure(file_pointer);
    }
    CheckErrorFile(file_pointer);

    fclose(file_pointer);
    CheckErrorClosed();
}

void PrintOrders() {

    FILE *file_ponter = fopen(ORDERS_FILE_NAME, "r"); 
    CheckErrorFile(file_ponter);

    customer_order *order = malloc(sizeof(customer_order));
    while(fscanf(file_ponter, ORDER_PATERN,
        &order->order_time, order->name, &order->toppings) == 3) {

        //convert time to text
        char time_buffer[100];
        strcpy(time_buffer, ctime(&order->order_time));
        
        //replace newline character with end of string null character
        time_buffer[strlen(time_buffer)-1] = '\0';

        //get list of toppings to exclude
        char toppings_buffer[255];
        ListExcludes(order->toppings, toppings_buffer);

        printf("%s %s %s\n", time_buffer, order->name, toppings_buffer);
    }
}
