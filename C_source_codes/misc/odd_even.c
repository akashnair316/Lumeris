#include <stdio.h>

#define ODD_EVEN_CHECK(n)   ((n) & 1U)

int main(void)
{
    int reg = 51;
    if(ODD_EVEN_CHECK(reg)) {
        printf("Number is ODD\r\n");
    } else {
        printf("Number is EVEN\r\n");
    }

    return 0;
}