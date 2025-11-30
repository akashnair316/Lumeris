#include <stdio.h>

int hack(int a, int b)
{
    /*  0xABCD
        0x1234
        0xA2C4

        0xABCD
        0xF0F0 AND
        0xA0C0

        0x1234
        0x0F0F AND
        0x0204

        0xA0C0
        0x0204 OR
        0xA2C4
    */
   a = (a & 0xF0F0);
   b = (b & 0x0F0F);

   return (a | b);
}


int main(void)
{
    int A = 0xABCD;
    int B = 0x1234;

    int C = hack(A, B);
    printf("%x\r\n", C);

    return 0;
}