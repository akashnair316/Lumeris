#include <stdio.h>


int main(void)
{
    int var = 0x12345678;

    char *ptr = NULL;
    ptr = (char *)&var;
    
    if (*ptr == 0x12) {
        printf("BIG\r\n");
    } else {
        printf("Little\r\n");
    }
    return  0;
}