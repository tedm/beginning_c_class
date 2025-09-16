// localtime2.c

#include <time.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    time_t mytime = time(NULL);
    char * time_str = ctime(&mytime);
    time_str[strlen(time_str)-1] = '\0';
    printf("Current Time : %s\n", time_str);

    return 0;
}
