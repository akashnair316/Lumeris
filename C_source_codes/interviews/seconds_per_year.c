#include <stdio.h>

/*
print Seconds per year
*/

#define SECONDS_PER_YEAR    (365UL * 24UL * 60UL * 60UL) /* UL is important */

int main(void)
{
    __uint64_t seconds = SECONDS_PER_YEAR; /* 128 bit cannot be printed by printf*/
    printf("Seconds in a year : %lu\r\n", seconds);
    return 0;
}