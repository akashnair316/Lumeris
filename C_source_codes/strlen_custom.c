#include <stdio.h>

/* Implement strlen()
Write your own my_strlen(const char *s) without using library functions.
Implement strcpy() Write my_strcpy(char *dst, const char *src).
*/
int my_strlen(const char *s)
{
    int length = 0;
    while (*s != '\0') {
        length++;    
        s = s + 1;
    }
    return length;
    //return number of bytes read;
}

int my_strcpy(char *dst, const char *src)
{
    while (*src != '\0') {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
}
int main(void)
{
    char src_buff[] = "Akash";
    char dst_buff[100];

    int length_str = my_strlen(src_buff);
    printf("STRLEN : %d\r\n", length_str);

    my_strcpy(dst_buff, src_buff);

    printf("%s\r\n", dst_buff);
    return 0;
}