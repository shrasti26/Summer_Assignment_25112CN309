#include <stdio.h>
int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int largest, second_largest;
    if (size < 2) {
        printf("Array must contain at least two elements.\n");
        return 1;
    }
    if (arr[0] > arr[1]) {
        largest = arr[0];
        second_largest = arr[1];
    } else {
        largest = arr[1];
        second_largest = arr[0];
    }
    for (int i = 2; i < size; i++) {
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }
    printf("The largest element is: %d\n", largest);
    printf("The second largest element is: %d\n", second_largest);

    return 0;
}
