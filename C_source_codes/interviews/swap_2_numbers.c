#include <stdio.h>

void swap_numbers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main(void)
{

    int a = 10;
    int b = 20;

    swap_numbers(&a, &b);

    printf("a : %d b : %d\r\n", a, b);
    return 0;
}