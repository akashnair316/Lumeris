#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data_map {
    char str[10]; //10 bytes
    struct data_map *next_ptr; //8 bytes --> 18 bytes
} __attribute__((packed)) data_map_s;

data_map_s *__head_ptr = NULL;

data_map_s * create_map(char *ptr_str)
{
    data_map_s *new_map = (data_map_s *)malloc(sizeof(data_map_s));

    /* Since this data is a STRING, we need to do the string operation here */
    memcpy(new_map->str, ptr_str, sizeof(new_map->str)-1);
    new_map->str[sizeof(new_map->str) - 1] = '\0';
    /* END OF DATA COPY */

    new_map->next_ptr = NULL;
    return new_map;
}

void add_map(char * ptr_str)
{
    data_map_s *new_map = create_map(ptr_str);
    /*Add the new_map to the start of list, by tweaking HEAD pointer*/
    new_map->next_ptr = __head_ptr;
    __head_ptr = new_map;
}

__uint8_t initialise(char *ptr_str)
{
    if (__head_ptr != NULL) {
        printf("Already initialised\r\n");
        return 1;
    }

    __head_ptr = create_map(ptr_str);
    return 0;
}

void display_map(void)
{
    data_map_s *temp = NULL;
    temp = __head_ptr;
    while (temp) {
        printf("Data in map : %s\r\n", temp->str);
        temp = temp->next_ptr;
    }
    
    free(__head_ptr);
}

int main(void)
{
    __uint8_t err_chk = 0;
    err_chk = initialise("Init-0");

    if (err_chk) {
        printf("Init error");
        return -1;
    }
    add_map("Akash");
    add_map("October");
    add_map("ABCDEFGHIJKLMNOP");
    
    display_map();
    

    return 0;
}
