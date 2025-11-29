#include <stdio.h>
#define BIT_ENDIA(var) ((var & (0xFF << 0)) << 24) \
                    |   ((var & (0xFF << 8)) << 8) \
                    |   ((var & (0xFF << 16)) >> 8) \
                    |   ((var & (0xFF << 24)) >> 24)
int main(void)
{
    int var = 0x12345678;
    var = BIT_ENDIA(var);

    printf("dbg : %x\r\n", var);
    return 0;
}