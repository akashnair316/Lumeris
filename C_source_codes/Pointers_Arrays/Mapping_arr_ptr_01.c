#include <stdio.h>

int main(void)
{
    int arr [] = {10, 20, 30};
    int *ptr = NULL;

    ptr = arr;

    printf("*ptr : %d\r\n", *(ptr));
    printf("*ptr + 1 : %d\r\n", *(ptr + 1));
    printf("*ptr + 2 : %d\r\n", *(ptr + 2));
 
    
 

    return 0;
}