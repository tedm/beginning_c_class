#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fileops.h"
#include "ingredients.h"

int main(int argc, char **argv) {

    if (argc > 1) {
        
        //load inventory
        int inventory[INGREDIENT_LIST_SIZE];
        ReadInventory(inventory, INGREDIENT_LIST_SIZE);
        
        //make sure name isn't an ingredient
        int match_name = MatchIngredient(argv[1]);
        if (match_name > -1) {
            printf("name cannot be an ingredient\n");
            Failure(NULL);
        }

        //start with all toppings
        int toppings = ALL_INGREDIENTS;

        for (int arg = 2; arg < argc; arg++) {
            int match = MatchIngredient(argv[arg]);
            if (match == -1) {
                printf("ingrdient not recognized (%s)\n", argv[arg]);
                Failure(NULL);
            }
            
            //make sure ingredient is already on the sandwich
            if (toppings & INGREDIENT_FLAGS[match])
                //remove ingredient
                toppings = toppings ^ INGREDIENT_FLAGS[match];
            else {
                printf("%s was already removed\n", argv[arg]);
                Failure(NULL);
            }
        }

        //verify all requested toppings are in the inventory
        for(int ingredient = 0; ingredient < INGREDIENT_LIST_SIZE; ingredient++) {
            
            //check to see if customer wants this ingtrdirnt
            if (toppings & INGREDIENT_FLAGS[ingredient]) {
                
                //check inventory
                if (inventory[ingredient] == 0) {
                    printf("not enough %s in inventory for the order\n", INGREDIENT_LIST[ingredient]);
                    Failure(NULL);
                }
                //set inventory
                else inventory[ingredient]--;
            }
        }

        //setup formatted order
        customer_order order;
        strcpy(order.name, argv[1]);
        order.toppings = toppings;
        order.order_time = time(NULL);

        //write files
        WriteOrder(&order);
        WriteInventory(inventory, INGREDIENT_LIST_SIZE);
        printf("order for %s was written\n", order.name);
    }
    
    //display orders
    else {
        PrintOrders();
    }

    printf("program exited normally with %d successfull error checks.\n",
        passed_error_checks);
    return EXIT_SUCCESS;
}