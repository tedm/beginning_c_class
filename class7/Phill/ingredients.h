/*
Ingredients for the Sandwich Shop programs
*/

#ifndef INGREDIENTS_H_
#define INGREDIENTS_H_

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

extern int MatchIngredient(char *arg);
extern const char *INGREDIENT_LIST[];
#define INGREDIENT_LIST_SIZE 8
#define INGREDIENT_MAX 10

#endif