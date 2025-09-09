#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "ingredients.h"
#include "fileops.h"

//creates a starter file
void *WriteStarter() {
    
    //manually reset the no file error
    errno = 0;

    //declare data to write
    int stock_amount = INGREDIENT_INVENTORY_MAX / 2;
    int inventory[INGREDIENT_LIST_SIZE];
    
    //loop through ingredients and set them all
    for (int x = 0; x < INGREDIENT_LIST_SIZE; x++)
        inventory[x] = stock_amount;

    //send array for writing
    WriteInventory(inventory, INGREDIENT_LIST_SIZE);

    printf("new inventory created\n");
}

//Matches an argument to an ingredient to add to inventory
int MatchArgument(char *arg) {
    int value = MatchIngredient(arg);
    
    //makes sure a positive value was returned
    if (value > -1) return value;
    printf("ingredient not recognized: %s\n", arg);
    Failure(NULL);
}

int GetValue(char *arg) {
    
    //make sure the argument isn't too long
    if (strlen(arg) > 20) {
        printf("too long to be converted into a number: %s\n", arg);
        Failure(NULL);
    }
    
    //parse the integer
    int value = atoi(arg);
    
    //turn it back into a string
    char check[20];
    sprintf(check, "%d", value);

    //compare the strings
    if (strcmp(arg, check) != 0) {
        //if they are unequal, something bad happened
        printf("%s and %s (%d) did not match.\n", check, arg, value);
        Failure(NULL);
    }

    //make sure the value is positive
    if (value > 0) return value;
    printf("%d is not a positive value.\n", value);
    Failure(NULL);
}

int main(int argc, char **argv) {
    
    int inventory[INGREDIENT_LIST_SIZE];
    ReadInventory(inventory, INGREDIENT_LIST_SIZE);
    
    //create file if it does not exist
    if (errno == 2) {
        WriteStarter();
        ReadInventory(inventory, INGREDIENT_LIST_SIZE);
    }
    
    //check to see if the amount of arguments can be used to add inventory
    if (argc == 3) {
        int ingredient = MatchArgument(argv[1]);
        int amount = GetValue(argv[2]);
        int total;

        //calculate the new total to test before writing
        total = amount + inventory[ingredient];

        //make sure the user can't overfill inventory
        if (total > INGREDIENT_INVENTORY_MAX) {
            printf("Total (%d) was greater than the inventory limit of %d.\n",
                total, INGREDIENT_INVENTORY_MAX);
            printf("Adding too many may cause spoilage!\n");
            Failure(NULL);
        }

        //check to see if something REALLY bad happened
        if (total < inventory[ingredient]) {
            printf("Adding (%d) somehow reduced inventory (%d) to (%d).\n",
                amount, inventory[ingredient], total);
            Failure(NULL);
        }

        //write
        inventory[ingredient] = total;
        WriteInventory(inventory, INGREDIENT_LIST_SIZE);

        printf("%d %s added to inventory for a total of %d.\n",
            amount, INGREDIENT_LIST[ingredient], total);
    }
    
    //display inventory
    else {
        printf("Current Inventory\n");
        printf("-----------------\n");
        for (int x = 0; x < INGREDIENT_LIST_SIZE; x++)
            printf("%s %d\n", INGREDIENT_LIST[x], inventory[x]);
    }

    printf("program exited normally with %d successfull error checks.\n",
        passed_error_checks);
    return EXIT_SUCCESS;
}