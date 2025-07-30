#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *filepointer = fopen("File.txt","r");
    if (filepointer == NULL)
    {
        fprintf(stderr, "File not found\n");
        exit(EXIT_FAILURE);
    }
    fclose(filepointer);
    printf("Job completed\n");
}
