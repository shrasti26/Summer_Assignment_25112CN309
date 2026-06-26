#include <stdio.h>
int main() {
    int arr[] = {4, 2, 4, 3, 2, 5, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i, j, k;

    printf("Original array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
        
            if (arr[i] == arr[j]) {
                
                for (k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--; 
                j--;    
            }
        }
    }

    printf("Array after removing duplicates: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
