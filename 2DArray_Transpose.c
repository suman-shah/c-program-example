#include <stdio.h>

// The transpose of a matrix using 2D Array

int main()
 {
  int arr[10][10], transpose[10][10], row, col, i, j;
  printf("Enter rows and columns: ");
  scanf("%d %d", &row, &col);
  printf("Enter the matrix elements: ");
  for (i = 0; i < row; ++i)
  for (j = 0; j < col; ++j)
   {
    printf("Enter element for a%d%d: ", i + 1, j + 1);
    scanf("%d", &arr[i][j]);
   }

  printf("The entered matrix is: \n");
  for (i = 0; i < row; ++i)
  for (j = 0; j < col; ++j) 
  {
    printf("%d  ", arr[i][j]);
    if (j == col - 1)
    printf("\n");
  }

  for (i = 0; i < row; ++i)
  for (j = 0; j < col; ++j) 
  {
    transpose[j][i] = arr[i][j];
  }
  
  printf("The transpose of the matrix is:\n");
  for (i = 0; i < col; ++i)
  for (j = 0; j < row; ++j) 
  {
    printf("%d  ", transpose[i][j]);
    if (j == row - 1)
    printf("\n");
  }

  return 0;
}
