#include <stdio.h>
#include <string.h>

int main(void)
{
    char buffer_dest[100];

    char buffer_src[100] = "Akash November 20 1422";

    memcpy(buffer_dest, buffer_src, sizeof(buffer_dest));

    printf("%s\r\n", buffer_dest);

    memset(buffer_dest, '0', sizeof(buffer_dest));
    printf("%s\r\n", buffer_dest);

    memmove(buffer_dest, buffer_src, sizeof(buffer_dest));
    printf("%s\r\n", buffer_dest);


    return 0;
}