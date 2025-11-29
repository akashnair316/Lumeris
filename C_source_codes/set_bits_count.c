#include <stdio.h>

int main(void)
{

    __uint8_t var = 0x08;

    //find number of bits set or enabled.
    //1111 1111
    //0000 0001

    __uint8_t mask = 0x01;
    __uint8_t count = 0;

    for(size_t i = 0 ; i < sizeof(mask)*8; i++) {
        if (var & mask) {
            count = count + 1;
        }
        mask = mask << 1;
    }
    printf("count : %d\r\n", count);

    return 0;
}