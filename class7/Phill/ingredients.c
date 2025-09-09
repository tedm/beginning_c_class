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

const char *INGREDIENT_LIST[] = {BACON, LETTUCE, TOMATO, ONION, TURKEY, CHEESE, MAYO, RANCH};