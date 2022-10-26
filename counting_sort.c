#include "stdio.h"

// implementation of scounting sort
void counting_sort(int arr[], int num_elems, int range){
    int counting_arr[range + 1];

    for (int i = 0; i<range + 1; i++){
        counting_arr[i] = 0;
    }

    for (int i = 0; i<num_elems; i++){
        counting_arr[arr[i]]++;
    }


    for (int i = 1; i < range + 1; i++){
        counting_arr[i] = counting_arr[i] + counting_arr[i-1];
    }

    int output_arr[num_elems];

    for (int i = num_elems - 1; i>=0; i--){
        output_arr[counting_arr[arr[i]] - 1] = arr[i];
        counting_arr[arr[i]]--;
    }

    for (int i = 0; i<num_elems; i++){
        arr[i] = output_arr[i];
    }
}

int main(){
    int arr[] = {89, 87, 36, 0, 89, 78, 0, 789, 1, 36};

    counting_sort(arr, sizeof(arr)/sizeof(arr[0]), 1000);

    for (int i = 0; i<sizeof(arr)/sizeof(arr[0]); i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}