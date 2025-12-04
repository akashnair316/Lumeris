#include <stdio.h>

void power_of_two(int *ptr)
{
    if (*ptr == 0) {
        printf("Not a valid address\r\n");
        return;
    }
    
    if (((*ptr) & (*ptr) - 1) == 0) { /* take away : == has higher precedence so be carefull with brackets*/
        printf("Power of 2\r\n");
    } else {
        printf("Not a Power of 2\r\n");
    }
}


int main(void)
{
    __uint32_t address = 0x10000001;
    power_of_two(&address);

    return 0;
}