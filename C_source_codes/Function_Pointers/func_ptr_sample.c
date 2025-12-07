#include <stdio.h>

struct package {
    char message[10];
    void (* func_ptr_1)(int);
    void (* func_ptr_2)(char *);
};

void func_1(int var)
{
    printf("Got variable modifying it : %d\r\n", var+10);
}

void func_2(char *msg)
{
    printf("Message is : %s\r\n", msg);
}

void init(void)
{
    struct package data = {
        .func_ptr_1 = func_1,
        .func_ptr_2 = func_2,
        .message = "Hi"
    };

    data.func_ptr_1(10);
    printf("Message : %s\r\n", data.message);
}

int main(void)
{

    init();

    return 0;
}