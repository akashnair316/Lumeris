#include <stdio.h>
int abc_g = 10;

void func_0(void)
{
    static int i = 9;
    func_1(i);
    printf("i 2: %d\r\n", i+1);
}

void func_1(int i)
{
    i = i + 1;
    printf("i : %d\r\n", i);
}

int main(void)
{

    func_0();
    
    //printf("i : %d\r\n", i);

    return 0;
}
