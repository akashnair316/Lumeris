#include <stdio.h>


/*
Pick a number.
Make that number standard : Move numbers small than number_pivot to left and larger one to right.
Pick a number in left and then again divide them into 2, same with right.

Pick 8
pivot = 8
go through array, place numbers less than 8 in left and greater than 8 in right.

5 3 8 9 2

arr[0] < 8

*/
void display_array(int *arr, int loop_count)
{
    int i = 0;
    for (i = 0; i < loop_count; i++) {
        printf("arr[%d]- %d\r\n", i, arr[i]);
    }
}


int main(void)
{
    int arr[5] = {5, 3, 8, 9, 2};
    e_sort(arr, sizeof(arr)/sizeof(arr[0]));
    

    return 0;
}