// storemultiplestrings.c
// storing multiple strings in a single structure


    #include <stdio.h>

    int main() {
        char *fruits[] = {"Apple", "Banana", "Cherry", "Date"};
        int num_fruits = sizeof(fruits) / sizeof(fruits[0]);

        for (int i = 0; i < num_fruits; i++) {
            printf("Fruit %d: %s\n", i + 1, fruits[i]);
        }
        return 0;
    }
