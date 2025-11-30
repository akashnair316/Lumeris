/*
int n = 0x87654321;
Check for endianness of 'n'. Create a function and pass values of n as little endian to one function and in another pass it as Big endian.
*/

#include <stdio.h>
#define CONVERT_ENDIAN_BIG(n) ((n & 0xFF) << 24) | ((n & 0xFF00) << 8) | ((n & 0xFF0000) >> 8) | ((n & 0xFF000000) >> 24)

int check_endian(int n)
{
    char *ptr;
    ptr = (char *)&n;
    if (*ptr == 0x87) {
        return 1;
    } else {
        return 0;
    }
}

int convert_endian(int n)
{
    /*
    convert n = 0x87654321;
            n = 0x21436587;
    */
    n = CONVERT_ENDIAN_BIG(n);

    return n;
}

void big_endian(int n)
{
    printf("Big Endian format : %x\r\n", n);
}

void little_endian(int n)
{
    printf("Little Endian format : %x\r\n", n);
}

int main(void)
{
    int n = 0x87654321;
    int endian = check_endian(n);
    if (endian) {
        big_endian(n);
    } else {
        n = convert_endian(n);
        little_endian(n);
    }
    

}

