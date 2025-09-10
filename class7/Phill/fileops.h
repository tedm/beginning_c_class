/*
Standardized File opperations
*/

#ifndef FILEOPS_H_
#define FILEOPS_H_

#include <stdio.h>
#include <time.h>
#include <inttypes.h>

#define INVENTORY_FILE_NAME "inventory.bin"
#define ORDERS_FILE_NAME "orders.txt"
#define ORDER_PATERN "%08x %s %02x\n"

#define ORDER_MAX_NAME_LENGTH 15

typedef struct {
    time_t order_time;
    char name[ORDER_MAX_NAME_LENGTH];
    uint8_t toppings;
}customer_order;

extern int passed_error_checks;
extern void Failure(FILE *file_pointer);
void CheckErrorFile(FILE *file_pointer);
void CheckErrorClosed();
void WriteInventory(int *ram_inventory, int size);
void ReadInventory(int *ram_inventory, int size);
void WriteOrder(customer_order *order);
void PrintOrders();

#endif