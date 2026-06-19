#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of the square: ");
    if (scanf("%d", &size) != 1 || size < 1) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (i == 1 || i == size || j == 1 || j == size) {
                printf("* ");
            } else {
                printf("  "); 
            }
        }
        printf("\n");
    }

    return 0;
}
