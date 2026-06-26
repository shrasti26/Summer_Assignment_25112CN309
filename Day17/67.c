#include <stdio.h>

int main() {
    int arr1[] = {1, 2, 4, 5, 6, 2};
    int arr2[] = {2, 3, 5, 7, 2};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("Array 1: ");
    for(int i = 0; i < size1; i++) printf("%d ", arr1[i]);
    
    printf("\nArray 2: ");
    for(int i = 0; i < size2; i++) printf("%d ", arr2[i]);

    printf("\nIntersection: ");
    for (int i = 0; i < size1; i++) {
        int alreadyPrinted = 0;
        for (int k = 0; k < i; k++) {
            if (arr1[i] == arr1[k]) {
                alreadyPrinted = 1;
                break;
            }
        }
        
        if (!alreadyPrinted) {
            for (int j = 0; j < size2; j++) {
                if (arr1[i] == arr2[j]) {
                    printf("%d ", arr1[i]);
                    break; 
                }
            }
        }
    }
    
    printf("\n");
    return 0;
}
