#include <stdio.h>
#include <stdint.h>

#define CLR_GREEN  "\x1b[32m"
#define CLR_RESET  "\x1b[0m"

#define DBG(fmt, ...) \
    printf(CLR_GREEN "[DBG] " CLR_RESET fmt "\n", ##__VA_ARGS__)



void reverse_8_bit(int n)
{
    n = ((n & 1) << 7) | ((n & (1<<1)) << 5) | ((n & (1<<2)) << 3) | ((n & (1<<3)) << 1) | ((n & (1<<4)) >> 1) | ((n & (1<<5)) >> 3) | ((n & (1<<6)) >> 5) | ((n & (1<<7)) >> 7);

    DBG("%X\r\n", n);
}

uint8_t reverse8(uint8_t n)
{
    n = (n >> 4) | (n << 4);
    n = ((n & 0xCC) >> 2) | ((n & 0x33) << 2);
    n = ((n & 0xAA) >> 1) | ((n & 0x55) << 1);


    /*
    n = 0000 1010
    0000 0000
    1010 0000
    n = 1010 0000

    1010 0000
    1100 1100

    1000 0000
    0010 0000 |


    */
    return n;
}

int main(void)
{

    uint8_t n = 0x5A;

   reverse_8_bit(n);
   n = reverse8(n);
   DBG("optimised : %X\r\n", n);

    return 0;
}