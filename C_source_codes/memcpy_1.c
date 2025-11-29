#include <stdio.h>
#include <string.h>

int main(void)
{
    char src_buffer[] = "Akash Nair";

    //char dst_buffer[100];

    memmove((src_buffer + 1), (src_buffer), 10);
    printf("Memove %s\r\n", src_buffer);

    memcpy((src_buffer + 1), (src_buffer), 10);
    printf("Memcpy %s\r\n", src_buffer);

    return 0;
}