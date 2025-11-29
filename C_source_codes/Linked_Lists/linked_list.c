#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data_map {
    int data_1; //4 bytes
    struct data_map *next_ptr; //8 bytes --> 12 bytes
} __attribute__((packed)) data_map_s;

data_map_s *__head_ptr = NULL;

data_map_s * create_map(int *data_1)
{
    data_map_s *new_map = (data_map_s *)malloc(sizeof(data_map_s));

    /* Since this data is a STRING, we need to do the string operation here */
    new_map->data_1 = *data_1;
    new_map->next_ptr = NULL;
    return new_map;
}

void add_map(int * data_ptr)
{
    data_map_s *new_map = create_map(data_ptr);
    /*Add the new_map to the start of list, by tweaking HEAD pointer*/
    new_map->next_ptr = __head_ptr;
    __head_ptr = new_map;
}

__uint8_t initialise(int *ptr_data)
{
    if (__head_ptr != NULL) {
        printf("Already initialised\r\n");
        return 1;
    }

    __head_ptr = create_map(ptr_data);
    return 0;
}

void display_map(void)
{
    data_map_s *temp = NULL;
    temp = __head_ptr;
    while (temp) {
        printf("Data in map : %d\r\n", temp->data_1);
        temp = temp->next_ptr;
    }
    free(__head_ptr);
}

int search_data(int data)
{
    data_map_s *temp = NULL;
    temp = __head_ptr;
    while (temp) {
        if (temp->data_1 == data) {
            printf("Data found\r\n");
            return 0;
        } 
        temp = temp->next_ptr;
    }
    printf("Not found in list\r\n");
}

int delete_data(int data_1)
{
    data_map_s *c, *p;
    c = __head_ptr;
    p = NULL;

    while (c) {
        if (c->data_1 == data_1) {
            p->next_ptr = c->next_ptr;
            free(c);
            return 0;
        }
        p = c;
        c = c->next_ptr;
    }
}

int main(void)
{
    __uint8_t err_chk = 0;
    int start_value = 9;
    int s_data = 99;

    err_chk = initialise(&start_value);

    if (err_chk) {
        printf("Init error");
        return -1;
    }

    for (int i = 95; i < 101; i++) {
        add_map(&i);
    }
    
    //search_data(s_data);
    delete_data(s_data);
    display_map();
    
    return 0;
}
