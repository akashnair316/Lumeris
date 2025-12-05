#include <stdio.h>

int main(void)
{
    int var_a = 0xAA;

    int *ptr_integer;
    ptr_integer = &var_a;

    printf("Address of ptr_integer : %p\r\n", ptr_integer);
    printf("Address of ptr_integer + 1: %p\r\n", ptr_integer + 1);

    char *chr_ptr = NULL;
    chr_ptr = (char *)&var_a;

    printf("Address of chr_ptr: %p\r\n", chr_ptr);
    printf("Address of chr_ptr + 1: %p\r\n", chr_ptr + 1);

    return 0;
}