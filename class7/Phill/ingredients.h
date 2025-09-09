/*
Ingredients for the Sandwich Shop programs
*/

#ifndef INGREDIENTS_H_
#define INGREDIENTS_H_

#include <inttypes.h>

//1 or 0x01
#define BACON "bacon"
#define BACON_FLAG 0b00000001

//2 or 0x02
#define LETTUCE "lettuce"
#define LETTUCE_FLAG 0b00000010

//4 or 0x04
#define TOMATO "tomatoes"
#define TOMATO_FLAG 0b00000100

//8 or 0x08
#define ONION "onions"
#define ONION_FLAG 0b00001000

//16 or 0x10
#define TURKEY "turkey"
#define TURKEY_FLAG 0b00010000

//32 or 0x20
#define CHEESE "cheese"
#define CHEESE_FLAG 0b00100000

//64 or 0x40
#define MAYO "mayonnaise"
#define MAYO_FLAG 0b01000000

//128 or 0x80
#define RANCH "ranch"
#define RANCH_FLAG 0b10000000

int MatchIngredient(char *arg);
void ListExcludes(uint8_t toppings, char *buffer);
extern const char *INGREDIENT_LIST[];
extern const int INGREDIENT_FLAGS[];
#define INGREDIENT_LIST_SIZE 8
#define INGREDIENT_INVENTORY_MAX 10
#define ALL_INGREDIENTS 0xff

#endif