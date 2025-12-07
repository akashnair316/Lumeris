#include <stdio.h>
#include <string.h>

int main(void)
{
    #if 0
    int var = 0xFF;

    printf("Shift - 24 : %8X\r\n", var << 24);
    printf("Shift - 16 : %8X\r\n", var << 16);
    printf("Shift - 8 : %8X\r\n", var << 8);
    printf("Shift - 0 : %8X\r\n", var << 0);
    #endif


    #if 1
    int var = 128;
    printf("Var : %d\r\n", var >> 3);

    #endif
    return 0;
}