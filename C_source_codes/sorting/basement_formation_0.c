#include <stdio.h>


/*
## Mental model as 
2 numbers : How you want to arrange it?
ascending or descending?
ascending consideration : 
if number at index 0 is greater than index 1 then this not correct.
We need to swap there positions.
Same with all the other elements in data structure or array.
This is bubble sorting --> The heaviest Bubble goes to the deepest location.

num_1 > num_2

for index=0
temp_var = arr[0];
arr[0] = arr[0+1];
arr[0+1] = temp;

increase index by 1

if num_1 > num_2
for index=1
temp_var = arr[1];
arr[1] = arr[1+1];
arr[1+1] = temp;

else
increase index by 1
*/

void display_array(int *arr, int loop_count)
{
    int i = 0;
    for (i = 0; i < loop_count; i++) {
        printf("arr[%d]- %d\r\n", i, arr[i]);
    }
}

void bubble_sort(int *arr, int loop_count)
{
    int i = 0, temp = 0, j = 0;
    for(j = 0; j < (loop_count - 1); j++) {
        for(i = 0; i < (loop_count - 1); i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    display_array(arr, loop_count);
}


int main(void)
{
    int arr[5] = {5, 3, 8, 9, 2};
    bubble_sort(arr, sizeof(arr)/sizeof(arr[0]));
    

    return 0;
}