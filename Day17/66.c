#include <stdio.h>

int main() {
    int arr1[] = {1, 3, 7, 5, 9};
    int arr2[] = {1, 4, 6, 7, 2};
    
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int unionArr[n1 + n2]; 
    int k = 0; 
    for (int i = 0; i < n1; i++) {
        unionArr[k++] = arr1[i];
    }

    
    for (int i = 0; i < n2; i++) {
        int isDuplicate = 0;
        
    
        for (int j = 0; j < k; j++) {
            if (arr2[i] == unionArr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            unionArr[k++] = arr2[i];
        }
    }

    printf("Union of the two arrays: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", unionArr[i]);
    }
    printf("\n");

    return 0;
}

