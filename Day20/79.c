#include <stdio.h>

int main() {
    int rows, cols, i, j;
    int matrix[100][100];
    int rowSum;

    
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    
    printf("\nEnter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    
    printf("\nThe entered matrix is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    
    printf("\nRow-wise Sum:\n");
    for (i = 0; i < rows; i++) {
        rowSum = 0; 
        for (j = 0; j < cols; j++) {
            rowSum += matrix[i][j]; 
        }
        printf("Sum of Row %d = %d\n", i + 1, rowSum);
    }

    return 0;
}

