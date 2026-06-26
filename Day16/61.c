#include <stdio.h>
int getMissingNumber(int arr[], int size) {
    int n = size + 1; 
    int expectedSum = (n * (n + 1)) / 2; 
    int actualSum = 0;
    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }
    return expectedSum - actualSum;
}

int main() {
    int arr[] = {1, 2, 4, 6, 3, 7, 8}; 
    int size = sizeof(arr) / sizeof(arr[0]);

    int missingNum = getMissingNumber(arr, size);

    printf("The missing number is: %d\n", missingNum);

    return 0;
}
