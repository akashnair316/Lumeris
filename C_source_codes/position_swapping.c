#include <stdio.h>

void change_pos(int pos_var)
{
    //12345678
    //F0F0F0F0 -> AND
    //10305070 --> save_1

    //12345678
    //0F0F0F0F --> AND
    //02040608 --> Save_2

    //save_2 << 1 --> 20406080
    //save_1 >> 1 --> 01030507 OR
    //                 21436587

    int save_1 = (pos_var & 0xF0F0F0F0) >> 4;
    printf("%x\r\n", save_1);
    int save_2 = (pos_var & 0x0F0F0F0F) << 4;
    printf("%x\r\n", save_2);

    pos_var = save_1 | save_2;
    printf("out : %x\r\n", pos_var);

    //12345678
    //0F0F0F0F
    //02040608 << 4
}

int main(void)
{
    int var = 0x12345678; //21436587

    change_pos(var);

    return 0;
}