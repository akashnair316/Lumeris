#include <stdio.h>
#include <stdint.h>


int main(void)
{
    uint8_t buffer[10];
    uint32_t *ptr = (uint32_t *)&buffer[1];
    *ptr = 0xDEADBEEF;

    printf("*ptr : %x\r\n", *ptr);
    return 0;
}

