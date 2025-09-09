#include <string.h>
#include "ingredients.h"

//tries to match an ingredient
//returns index of ingredient or -1 if none match
//in real life, you would use a smarter algorithm
int MatchIngredient(char *arg) {
    for (int x = 0; x < INGREDIENT_LIST_SIZE; x++)
        if (strcmp(arg, INGREDIENT_LIST[x]) == 0)
            return x;
    return -1;
}

void ListExcludes(uint8_t toppings, char *buffer) {
    int cursor = 0;
    for (int x = 0; x < INGREDIENT_LIST_SIZE; x++) {
        
        //look for ingredients NOT(!) included
        if (!(toppings & INGREDIENT_FLAGS[x])) {
            
            //get the length of the name of the ingredient to add
            int add_size = strlen(INGREDIENT_LIST[x]);
            
            //coppy it into the buffer
            strncpy(&buffer[cursor], INGREDIENT_LIST[x], add_size);
            
            //increment the cursor
            cursor += add_size;
            
            //add a space to the buffer and increment the cursor
            buffer[cursor++] = ' ';
        }
    }
    //terminate the string
    buffer[cursor] = '\0';
}

const char *INGREDIENT_LIST[] = {BACON, LETTUCE, TOMATO, ONION, TURKEY, CHEESE, MAYO, RANCH};
const int INGREDIENT_FLAGS[] = {BACON_FLAG, LETTUCE_FLAG, TOMATO_FLAG,
    ONION_FLAG, TURKEY_FLAG, CHEESE_FLAG, MAYO_FLAG, RANCH_FLAG};