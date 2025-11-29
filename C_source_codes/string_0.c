#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[11];
    int value = 25;

    snprintf(buf, sizeof(buf), "Value : %d", value);

    printf("buffer - %s\r\n", buf);
    printf("String length of BUFFER : %ld\r\n", strlen(buf));
    int i = 0;

    while (*(buf + i) != 0x0) {
        printf("%c", *(buf + i));
        i++;
    }
    

    return 0;

}