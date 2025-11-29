#include <stdio.h>
#include <string.h>


int main(void)
{

    char str[] = "Hello";
    char *ptr = "Akash";


    int i = 0, j = 0;
    for(j = 0; j < strlen(ptr); j++) {
        printf("str[%d] - %c\r\n", j, str[j]);
    }

    printf("\r\n");

    for(i = 0; i < strlen(str); i++) {
        printf("str[%d] - %c\r\n", i, str[i]);
    }

    return 0;
}