#include <stdio.h>

int main() {
    int rows, cols;

    
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    
    int first[rows][cols];
    int second[rows][cols];
    int difference[rows][cols];

    
    printf("\nEnter elements of the first matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &first[i][j]);
        }
    }

    
    printf("\nEnter elements of the second matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &second[i][j]);
        }
    }

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            difference[i][j] = first[i][j] - second[i][j];
        }
    }

    
    printf("\nResultant Matrix (First - Second):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", difference[i][j]);
        }
        printf("\n");
    }

    return 0;
}

