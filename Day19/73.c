#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int rows, cols, i, j;
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], sum[MAX_SIZE][MAX_SIZE];


    printf("Enter rows and columns (1-100): ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of 1st matrix:\n");
    for (i = 0; i < rows; ++i)
        for (j = 0; j < cols; ++j)
            scanf("%d", &matrix1[i][j]);

    printf("Enter elements of 2nd matrix:\n");
    for (i = 0; i < rows; ++i)
        for (j = 0; j < cols; ++j)
            scanf("%d", &matrix2[i][j]);

    
    printf("\nSum of matrices:\n");
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}
