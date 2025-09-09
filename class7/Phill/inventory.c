#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "ingredients.h"

#define ADD "add"
#define FILE_NAME "inventory.bin"

int passed_error_checks = 0;
FILE *file_pointer;

//generic failure program end
void Failure() {
    printf("program failed\n");
    fclose(file_pointer);
    exit(EXIT_FAILURE);
}

//means of checking for file pointer errors
void CheckError() {
    
    //shut down the program if something bad happens
    if (ferror(file_pointer) != 0) {
        printf("Error number: %d\n", errno);
        perror("perror");
        printf("strerror: %s\n", strerror(errno));
        Failure();
    }
    
    //success counter
    passed_error_checks++;
}

//creates a starter file
void *WriteStarter() {
    
    //manually reset the no file error
    errno = 0;

    //create file
    file_pointer = fopen(FILE_NAME, "wb");
    CheckError();
    
    //declare data to write
    int stock_amount = INGREDIENT_MAX / 2;
    
    //loop through ingredients and write them all
    for (int x = 0; x < INGREDIENT_LIST_SIZE; x++) {
        fwrite(&stock_amount, sizeof(int), 1, file_pointer);
        CheckError();
    }

    //reopen for reading
    freopen(FILE_NAME, "rb", file_pointer);
    CheckError();

    printf("new inventory created\n");
}

//Matches an argument to an ingredient to add to inventory
int MatchArgument(char *arg) {
    int value = MatchIngredient(arg);
    
    //makes sure a positive value was returned
    if (value > -1) return value;
    printf("ingredient not recognized: %s\n", arg);
    Failure();
}

int GetValue(char *arg) {
    
    //make sure the argument isn't too long
    if (strlen(arg) > 20) {
        printf("too long to be converted into a number: %s\n", arg);
        Failure();
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
        Failure();
    }

    //make sure the value is positive
    if (value > 0) return value;
    printf("%d is not a positive value.\n", value);
    Failure();
}

int main(int argc, char **argv) {
    
    //try to open the file
    file_pointer = fopen(FILE_NAME, "rb");
    
    //create file if it does not exist
    if (file_pointer == NULL && errno == 2) WriteStarter();
    //error check if something bad happened
    else CheckError();
    
    //check to see if the amount of arguments can be used to add inventory
    if (argc == 3) {
        int ingredient = MatchArgument(argv[1]);
        int amount = GetValue(argv[2]);
        int inventory[INGREDIENT_LIST_SIZE];
        int total;

        //read the current inventory
        fread(&inventory, sizeof(int), INGREDIENT_LIST_SIZE, file_pointer);
        CheckError();

        //calculate the new total to test before writing
        total = amount + inventory[ingredient];

        //make sure the user can't overfill inventory
        if (total > INGREDIENT_MAX) {
            printf("Total (%d) was greater than the inventory limit of %d.\n",
                total, INGREDIENT_MAX);
            printf("Adding too many may cause spoilage!\n");
            Failure();
        }

        //check to see if something REALLY bad happened
        if (total < inventory[ingredient]) {
            printf("Adding (%d) somehow reduced inventory (%d) to (%d).\n",
                amount, inventory[ingredient], total);
            Failure();
        }

        //reopen file for writing
        freopen(FILE_NAME, "wb", file_pointer);
        CheckError();

        //write
        inventory[ingredient] = total;
        fwrite(&inventory, sizeof(int), INGREDIENT_LIST_SIZE, file_pointer);
        CheckError();

        printf("%d %s added to inventory for a total of %d.\n",
            amount, INGREDIENT_LIST[ingredient], total);
    }
    
    //display inventory
    else {
        printf("Current Inventory\n");
        printf("-----------------\n");
        for (int x = 0; x < INGREDIENT_LIST_SIZE; x++) {
            
            //declare a space to read
            int amount;
            
            //read
            fread(&amount, sizeof(int), 1, file_pointer);
            CheckError(file_pointer);
            
            //display
            printf("%s %d\n", INGREDIENT_LIST[x], amount);
        }
    }

    //close the file
    fclose(file_pointer);
    
    //The pointer is freed and can no longer be accessed!!
    //Our shortcut method will no longer work!!
    //Checking error number directly instead.
    if (errno != 0 ) {
        printf("Close File Error\n");
        printf("Error number: %d\n", errno);
        perror("perror");
        printf("strerror: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("program exited normally with %d successfull error checks.\n",
        passed_error_checks);
    return EXIT_SUCCESS;
}