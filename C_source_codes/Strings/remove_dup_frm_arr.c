#include<stdio.h>

void remove_dup(int *arr, int num_element)
{
    //printf("num_element: %d\r\n", num_element); //9
    //printf("%d\r\n", *(arr + 5));
    //printf("n = %d\r\n", arr[5]);

    int k = 0;
    int new_arr[5] = {};
    int found = 0;
    
    #if 1
    for (size_t i = 0; i < num_element; i++) {
        found  = 0;
        for (size_t j = i+1; j < num_element; j++) {
            if (arr[i] == arr[j]) {
                //Match found
                found = 1;
                break;
            }
        }
        if(!found) {
           new_arr[k] = arr[i];
            k = k + 1;
        }
    }

    for (size_t i = 0; i < k; i++) {
        printf("New array : %d\r\n", new_arr[i]);
    }
    #endif

}


int main(void)
{

    /* Remove duplicate element from array */
    int arr[] = {1,2,4,5,3,5,2,5,2};
    /*output : new_arr[] = {1,2,3,4,5}*/

    remove_dup(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}