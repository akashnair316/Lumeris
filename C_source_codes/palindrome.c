#include <stdio.h>
#include  <string.h>
//palindrome : NOON --> NOON : POOP POP

#define DBG_INT(x) printf("[DBG_INT] %d\r\n", x);
#define DBG_STR(x) printf("[DBG_STR] %s\r\n", x);
#define DBG_CHAR(x) printf("[DBG_CHAR] %c\r\n", x);

char temp[10];
void reverse_src_buffer(char *src_buffer, int size)
{
    int j = 0;

    for (int i = size -1; i >= 0; i--) {
        *(temp + j) = *(src_buffer + i);
        j = j + 1;
    }
    temp[j] = '\0';
}
int main(void)
{
    char src_buffer[10] = "NOOB";
    reverse_src_buffer(src_buffer, strlen(src_buffer));
    
    if(memcmp(src_buffer, temp, strlen(src_buffer)) == 0) {
        DBG_STR("String is Palindrome");
    } else {
        DBG_STR("String is not Palindrome");
    }
    return 0;
}