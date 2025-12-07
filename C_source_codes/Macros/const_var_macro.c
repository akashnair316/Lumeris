#include <stdio.h>
#include <stdlib.h>

#define DBG(x) printf("[DBG] %d\r\n", x)
void check_func(int var_copy)
{
    var_copy = var_copy + 1;
    DBG(var_copy);
}

int main(void)
{
    const int var = 90;
    check_func(var);
    /* Not possible to do
    var = var + 1;
    DBG(var);
    */

    int *ptr = &var;
    *ptr = *ptr + 1;
    DBG(*ptr);

    return 0;
}