#include <stdio.h>

#define DBG(str) printf("[DBG_STR]-%s\r\n", str);
int main(void)
{
    char buffer[20] = "Akash is here";
    DBG(buffer);

    snprintf(buffer, );

}