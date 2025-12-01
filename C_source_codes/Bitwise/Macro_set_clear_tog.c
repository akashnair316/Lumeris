#include <stdio.h>

/*
Generic Macro for SET - CLEAR - TOGGLE
prototype : given a 32 bit value.
          : Position
          : Action
*/

#define SET_BIT(n, pos) (n | (1 << pos))
#define CLEAR_BIT(n, pos) (n & ~(1 << pos))
#define TOGGLE_BIT(n, pos) (n ^ (1 << pos))


enum action {
    SET = 0,
    CLEAR,
    TOGGLE
};

void bit_action(int n, __uint8_t pos, enum action curr_act)
{
    switch (curr_act) {
    case SET:
        n = SET_BIT(n, pos);
        printf("n = 0x%X\r\n", n);
        break;
    case CLEAR:
        n = CLEAR_BIT(n, pos);
        printf("n = 0x%X\r\n", n);
        break;
    case TOGGLE:
        n = TOGGLE_BIT(n, pos);
        printf("n = 0x%X\r\n", n);
        break;
    default:
        printf("Error Data entered is not correct\r\n");
        break;
    }
}


int main(void)
{

    int n = 0x22;
    __uint8_t pos = 5;
    enum action curr_act;
    curr_act = TOGGLE;
    bit_action(n, pos, curr_act);

    return 0;
}