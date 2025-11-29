#include <stdio.h>

//int var = 0x87654321; //output -> 0x78563412;

#define ONE_BYTE_SWAP(x) x = ((x & 0xF0) >> 4) | (x << 4) ;


int main(void)
{
    __uint8_t data = 0x98;
    ONE_BYTE_SWAP(data);

    //__uint16_t var = 0x5612;
    __uint16_t var = 0x5487;
    var = ( ((var & 0xF000) >> 4) | ((var & 0xF00) << 4)) |\
            ((var & 0xF0) >> 4) | (var << 4);
      printf("2 byte data : %x\r\n", var);

    printf("one byte data : %x\r\n", data);
    return 0;
}