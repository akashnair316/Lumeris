// input : Hello,,   WoRld!!!   Welcome   to  C-programming...  
// your own version of: my_strlen

//reverse a full string : "Akash is a Embedded Engineer"
//Out : Engineer Embedded is Akash

#include <stdio.h>

#define DBG_STR(x) printf("DBG_STR : %s\r\n", x)
#define DBG_CHAR(x) printf("DBG CHAR : %c\r\n", x)
#define DBG_HEX(x) printf("DBG HEX : %x\r\n", x)
#define DBG_INT(x) printf("DBG INT : %d\r\n", x)
void reverse(char *str_cpy)
{
    char temp[100];
    int i = 0, j = 0;

    while (*(str_cpy + i) != '\0') {
        i = i + 1;
    }

    j = i;
    while(1) {
        if(*(str_cpy + j) == 0x20) {
            break;
        }
        j = j - 1;
    }

    int k = 0;
    int x = 0;
    for (k = j + 1; k < i; k++) {
        temp[x] = *(str_cpy + k);
        x = x + 1;
    }
    temp[x] = '\0';
    
    DBG_STR(temp);

}
int main(void)
{
    const char str[] = "Akash is a Embedded Engineer";

    reverse(str);
    

    return 0;
}