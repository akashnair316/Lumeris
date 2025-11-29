#include <stdio.h>

int main(void)
{
    /* Reverse a byte : mirror the bits*/
    /* sample : int i = 5; 0000 0101*/
    /*mirror : out = 0xC0; 1010 0000*/

    int i = 5;
    int j = 0;
    int mask = 1;
    int bit = 0;
    int k = 0;
    int final = 0;

    
        for(k = 7; k > 0; k--) {
            bit = i & mask; //new = 0000 0010 => 0000 0000
            bit = bit << k; //0000 0000
            final = final | bit;
            i = i >> 1;
        }
    

    printf("final : %x\r\n", final);

    return 0;
}