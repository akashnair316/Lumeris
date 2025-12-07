#include <stdio.h>

#define DEBUG(fmt, ...) printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)

// Type-safe macros without explicit type specification
#define swap(a, b) \
    do { \
        typeof(a) __tmp = (a); \
        (a) = (b); \
        (b) = __tmp; \
    } while (0)



int main(void)
{
    int var = 90;
    int a = 89;
    int b = 900;
    DEBUG("var : %d", var/10);
    swap(a,b);
    DEBUG("a : %d b : %d\r\n", a, b);
    return 0;
}