#include <stdio.h>
int main (){
  int arr[7] = {1, 9, -6, -8, -9, 4, 4};
  int largest, temp;
  
  for(int i = 6; i > 0; i--){
    largest = 0;
    for(int j = 0; j<= i; j++){
      if(arr[j] > arr[largest]){
        largest = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
  }
  
  //printing the sorted array now 
  for(int i = 0; i < 7; i++){
    printf("%d ", arr[i]);
  }
  return 0;
}
