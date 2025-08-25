// commandline.c

#include <stdio.h>

int main(int argc, char *argv[]) {

    printf("Number of arguments: %d\n", argc);
      for (int i = 0; i < argc; i++) {
            printf("Argument %d: %s\n", i, argv[i]);
      }
      return 0;
}

// you can replace the main() parameters with (int argc, char **argv), 
// there are no sematic differences
