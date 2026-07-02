#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function prototypes
void create(int arr[], int *n);
void display(int arr[], int n);
void insert(int arr[], int *n);
void deleteElement(int arr[], int *n);
void search(int arr[], int n);

int main() {
    int arr[MAX_SIZE];
    int n = 0; // Current size of the array
    int choice;

    while (1) {
        printf("\n=============================");
        printf("\n  ARRAY OPERATIONS SYSTEM");
        printf("\n=============================");
        printf("\n1. Create Array");
        printf("\n2. Display Array");
        printf("\n3. Insert Element");
        printf("\n4. Delete Element");
        printf("\n5. Search Element");
        printf("\n6. Exit");
        printf("\n=============================");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create(arr, &n);
                break;
            case 2:
                display(arr, n);
                break;
            case 3:
                insert(arr, &n);
                break;
            case 4:
                deleteElement(arr, &n);
                break;
            case 5:
                search(arr, n);
                break;
            case 6:
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

// 1. Create the array with user input
void create(int arr[], int *n) {
    int i;
    printf("\nEnter the number of elements (Max %d): ", MAX_SIZE);
    scanf("%d", n);

    if (*n < 0 || *n > MAX_SIZE) {
        printf("Invalid size! Resetting size to 0.\n");
        *n = 0;
        return;
    }

    printf("Enter %d elements:\n", *n);
    for (i = 0; i < *n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Array created successfully!\n");
}

// 2. Display the array elements
void display(int arr[], int n) {
    int i;
    if (n == 0) {
        printf("\nArray is empty! Nothing to display.\n");
        return;
    }

    printf("\nArray Elements: [ ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// 3. Insert an element at a specific index
void insert(int arr[], int *n) {
    int i, element, pos;

    if (*n >= MAX_SIZE) {
        printf("\nArray Overflow! Cannot insert more elements.\n");
        return;
    }

    printf("\nEnter the position (0 to %d) to insert: ", *n);
    scanf("%d", &pos);

    if (pos < 0 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &element);

    // Shift elements to the right to make space
    for (i = *n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos] = element;
    (*n)++; // Increase array size
    printf("Element inserted successfully!\n");
}

// 4. Delete an element from a specific index
void deleteElement(int arr[], int *n) {
    int i, pos;

    if (*n == 0) {
        printf("\nArray Underflow! No elements to delete.\n");
        return;
    }

    printf("\nEnter the position (0 to %d) to delete: ", *n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= *n) {
        printf("Invalid position!\n");
        return;
    }

    printf("Deleted element: %d\n", arr[pos]);

    // Shift elements to the left to close the gap
    for (i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--; // Decrease array size
    printf("Element deleted successfully!\n");
}

// 5. Search for an element (Linear Search)
void search(int arr[], int n) {
    int i, key, found = 0;

    if (n == 0) {
        printf("\nArray is empty! Nothing to search.\n");
        return;
    }

    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at index %d (Position %d).\n", i, i + 1);
            found = 1;
            break; // Stop searching once found
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", key);
    }
}
