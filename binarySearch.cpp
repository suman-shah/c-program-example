#include <iostream>


int binarySearch(int arr[], int left, int right, int x) {
  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == x) {
      return mid;
    } else if (arr[mid] < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}

int main() {
  int myarr[10];
  int num;
  int output;

  std::cout << "Please enter 10 elements ASCENDING order" << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cin >> myarr[i];
  }
    
  std::cout << "Please enter an element to search" << std::endl;
  std::cin >> num;

  output = binarySearch(myarr, 0, 9, num);

  if (output == -1) {
    
       std::cout << "No Match Found" << std::endl;
  } else {
    std::cout << "Match found at position: " << output << std::endl;
  }

  return 0;
}
