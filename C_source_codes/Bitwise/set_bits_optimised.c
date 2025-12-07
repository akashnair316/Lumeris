#include <stdio.h>

#define CLR_GREEN  "\x1b[32m"
#define CLR_RESET  "\x1b[0m"

#define DBG(fmt, ...) \
    printf(CLR_GREEN "[DBG] " CLR_RESET fmt "\n", ##__VA_ARGS__)
 
unsigned int set_bit_count(unsigned int var_cpy)
{
    /*
    0xAB : 10 11
    0000 0000 0000 0000 1010 1011
    0000 0000 0000 0000 0000 0001
    
    0000 0000 0000 0000 1010 1010
    0000 0000 0000 0000 1010 1001
    0000 0000 0000 0000 1010 1000

    0000 0000 0000 0000 1010 1011
    0000 0000 0000 0000 1010 1010
&   0000 0000 0000 0000 1010 1010
    0000 0000 0000 0000 1010 1001
&   0000 0000 0000 0000 1010 1000
    0000 0000 0000 0000 1010 0111
&   0000 0000 0000 0000 1010 0000
    */

/*
0111
0110
0110
0101
0100
0011
0000


*/

    unsigned int n = 1;
    unsigned int count = 0;
    while (n) {
        if(var_cpy & n)
            count = count + 1;
        n = n << 1;
    }
    DBG("Count : %d", count);
}

void optimised_count(int n)
{
    unsigned int count = 0;

    while (n > 0) {
        n = n & (n - 1);
        count++;
    }
    DBG("From optimised : %d\r\n", count);
}

int main(void)
{

    unsigned int var = 0xA;
    set_bit_count(var);
    optimised_count(var);

    return 0;
}