#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct student {
    int roll_no;
    char name[20];
    void (* func_ptr)(void *);
};

void data_print(void *loc_cpy_ptr)
{
    struct student *ptr = NULL;
    ptr = (struct student *)loc_cpy_ptr;
    printf("Name - %s\r\n", ptr->name);
    printf("Roll number - %d\r\n", ptr->roll_no);
}

int main(void)
{
    struct student *ptr = NULL;

    ptr = (struct student *)malloc(sizeof(struct student));
    
    char loc_buffer[] = "Akash";
    strncpy(ptr->name, loc_buffer, strlen(loc_buffer)+1);

    ptr->roll_no = 10;
    ptr->func_ptr = data_print;
    ptr->func_ptr(ptr);

    return 0;
}