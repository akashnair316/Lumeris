#include <stdio.h>
#include <stdlib.h>

struct data_node {
    __uint32_t var;
    char byte[2];
};

void power_of_two(void *ptr)
{
    __uint64_t addr = (__uint64_t)ptr;
    printf("Address : 0x%lx\r\n", addr);

    __uint8_t N = 8; //alignment bytes
    /*
    0xA0 is aligned to 8 bytes or not
    1010 0000 
    0000 1000

    1010 0000
    0000 0111
    0000 0000
    */

    if (addr == 0) {
        printf("Not a valid address\r\n");
        return;
    }

    if ((addr & (N - 1)) == 0) {
        printf("Aligned  address with 8 bytes\r\n");
    } else {
        printf("Not an Aligned  address with 8 bytes\r\n");
    }
    
}
int main(void)
{
    /* Check if memory address is aligned or not */
    void *ptr = NULL;
    struct data_node data_1;

    ptr = (struct data_node *)malloc(sizeof(data_1));

    printf("Address of data_node : %p\r\n", ptr);
    //printf("sizeof: data_1 : %ld\r\n", sizeof(data_1));

    power_of_two(ptr);

#if 0
    char *ptr_chr = (char *)ptr;
    printf("ptr_chr : %p\r\n", ptr_chr - 1);
#endif
    


    return 0;
}