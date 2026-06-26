#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_element = arr[0];
    int max_count = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            max_element = arr[i];
        }
    }
    printf("\nElement with maximum frequency: %d\n", max_element);
    printf("It appears %d times.\n", max_count);

    return 0;
}
