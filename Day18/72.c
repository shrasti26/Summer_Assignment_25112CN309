#include <stdio.h>

int main() {
    
    int arr[] = {5, 2, 8, 1, 9, 3};
    int temp;
    
    
    int size = sizeof(arr) / sizeof(arr[0]);

    
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    
    printf("Sorted array in descending order: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
