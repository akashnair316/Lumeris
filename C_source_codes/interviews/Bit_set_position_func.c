/*
Implement a function to check if a specific bit is set within a large bitfield represented by an array of 32-bit integers."
Input: An array of integers (int *array), the total size of the array, and the absolute bit position to check (bitpos).
Output: Return 1 (or true) if the bit is set, 0 (or false) otherwise.
Key Challenge: Mapping a linear bit position (like 100) to the correct array index and bit offset.
*/
#include <stdio.h>

void check_checkbit(int *array, int bitpos, int array_size)
{
/*
    Need to check if bitpos-100 is set or not?
    160 bytes -- 0 to 159
    We need index and bit position inside index.
    index = bitpos / 32;
    inside_bitpos = bitpos % 32;
*/
    __uint8_t index = 0;
    __uint8_t inside_bitpos = 0;

    index = bitpos / 32;
    inside_bitpos = bitpos % 32;

    int var = array[index];
    int mask = 0x1;
    mask = mask << inside_bitpos;
    if(var & mask) {
        printf("Set\r\n");
    } else {
        printf("Not Set\r\n");
    }
}

int main(void)
{
    int arr[] = {10, 20, 30, 56, 50}; //5*4bytes = 20 bytes = 20*8 = 160 bits
    //0011 1000
    
    check_checkbit(arr, 100, sizeof(arr));

    return 0;
}