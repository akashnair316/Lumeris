#include <stdio.h>


#define swap_nibble(n)  (   (((n) >> 4) & 0x0F)  | \
                            ((n) << 4) & 0xF0     \
                        )
#define swap_2_bit(n)   ( (((n) & 0x33) << 2) |   \
                          (((n) & 0xCC) >> 2)     \
                        )

#define swap_1_bit(n)   ( (((n) & 0x55) << 1) | \
                          (((n) & 0xAA) >> 1)  \
                        )

/*
*/

int main(void)
{
    __int32_t var = 0xA2;

    var = swap_nibble(var);
    printf("After swap _nibble : 0x%X\r\n", var);

    var = swap_2_bit(var);
    printf("After swap _2_bit : 0x%X\r\n", var);

    var = swap_1_bit(var);
    printf("After swap _1_bit : 0x%X\r\n", var);

    return 0;
}