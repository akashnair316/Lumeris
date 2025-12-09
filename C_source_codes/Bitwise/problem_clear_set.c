/*"Given a 32-bit register, write a macro to clear bits 5-10 and set bit 3, without affecting other bits."*/
#include <stdio.h>

#define SET_BIT(n, pos) (n | (1 << pos))
#define CLEAR_BIT(n, pos) (n & ~(1 << pos))
#define TOGGLE_BIT(n, pos) (n ^ (1 << pos))

#if 1
int main(void)
{
    __int32_t reg = 0xA2; 
    /*
    0000 1010 0010
    0111 1110 0000

    0000 1010 0010
    1000 0001 1111
    0000 0000 0010
    */
   __uint16_t mask = 0x7E0;
   mask = ~(mask);
   reg = reg & mask;
   printf("Clear 5-10 : 0x%x\r\n", reg);

   mask = 0x00;
   mask = 1U << 3;
   reg = reg | mask;

   printf("set 3rd bit : 0x%x\r\n", reg);

   return 0;

}

#endif