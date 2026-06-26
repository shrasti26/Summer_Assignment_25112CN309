#include <stdio.h>

int main() {
    
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {5, 6, 7};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int sizeMerged = size1 + size2;
    int merged[sizeMerged];
    
    int i, j;
    for (i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }
    for (j = 0; j < size2; j++) {
        merged[size1 + j] = arr2[j]; 
    }
    printf("Merged Array: ");
    for (i = 0; i < sizeMerged; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
