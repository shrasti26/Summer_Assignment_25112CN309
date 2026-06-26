#include <stdio.h>
int main() {
    int size;
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }
    int arr[size];
    int visited[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; 
    }
    printf("\nDuplicate elements in the array are:\n");
    int found_duplicate = 0;
    for (int i = 0; i < size - 1; i++) {
        if (visited[i] == 1) {
            continue;
        }
        int is_current_duplicate = 0;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                is_current_duplicate = 1;
                visited[j] = 1; 
            }
        }
        if (is_current_duplicate) {
            printf("%d ", arr[i]);
            found_duplicate = 1;
        }
    }

    if (!found_duplicate) {
        printf("None. All elements are unique.");
    }
    printf("\n");

    return 0;
}
