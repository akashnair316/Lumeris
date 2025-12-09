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


__int8_t swap_8_bit(__int8_t var)
{
    var = swap_nibble(var);
    var = swap_2_bit(var);
    var = swap_1_bit(var);

    return var;
}

int main(void)
{

    __int32_t var = 0xDEADBEEF;
    __uint8_t i = 0;
    char *ptr = NULL;
    ptr = (char *)&var;

    __int8_t final = 0;

    for(i = 0; i < 4; i++) {
        //printf("ptr : 0x%X\r\n", (unsigned char)*ptr);
        final = swap_8_bit(*ptr);
        printf("reverse : 0x%X\r\n", final);
        ptr = ptr + 1;
    }

    return 0;
}