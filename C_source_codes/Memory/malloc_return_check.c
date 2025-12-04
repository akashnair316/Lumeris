#include <stdio.h>
#include <stdlib.h>

void func(void)
{
    int *ptr[5];
    int i = 0;
    for(i = 0; i < 5; i++) {
        ptr[i] = (int *)malloc(4);
        printf("Address of ptr 4 bytes ptr[%d] : %p\r\n", i, ptr[i]);
    }
}

int main(void)
{
    func();

    return 0;
}