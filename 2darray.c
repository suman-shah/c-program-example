 #include <stdio.h>
  int main() {
        int i, j, k, a, n, temp;

        /* get the order of the matrix from the user */
        printf("Enter the order of the matrix:");
        scanf("%d", &n);
        int mat[n][n];

        /* get the matrix entries from the user */
        printf("Enter your entries for the input mat:\n");
        for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                        scanf("%d", &mat[i][j]);
                }
        }

        /* sort the contents of the two dimensional array */
        for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                        temp = mat[i][j];
                        a = j + 1;
                        for (k = i; k < n; k++) {
                                while (a < n) {
                                        /* swapping the data */
                                        if (temp < mat[k][a]) {
                                                temp = mat[k][a];
                                                mat[k][a] =mat[i][j];
                                                mat[i][j] = temp;
                                        }
                                        a++;
                                }
                                a = 0;     // to continue sorting in consecutive rows 
                        }
                }
        }

        /* print the result */
        printf("\n");
        printf("Sorted Matrix in decending order:\n");
        for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                        printf("%d ", mat[i][j]);
                }
                printf("\n");
        }
        return 0;
  }
