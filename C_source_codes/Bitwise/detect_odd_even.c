#include <stdio.h>
#include <stdint.h>

uint32_t swap_odd_even(uint32_t x) {
    // 0xAA... is 1010... (Even bits)
    // 0x55... is 0101... (Odd bits)
    return ((x & 0xAAAAAAAA) >> 1) | ((x & 0x55555555) << 1);
}


int main(void)
{
    __int32_t var = 0x7;
    printf("var : %X\r\n", var);
    var = swap_odd_even(var);
    printf("var : %X\r\n", var);

    return 0;
}