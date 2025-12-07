#include <stdio.h>

int main(void)
{
    __int8_t a = 0xFF;

    printf("value of a : %x\r\n", a<<8);

    return 0;
}