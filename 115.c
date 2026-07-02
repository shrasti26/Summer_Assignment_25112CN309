#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to helper-clear trailing newline from fgets
void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Function to flush standard input buffer
void flush_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char str1[100], str2[100], result[200];
    int choice;

    do {
        // Display Menu
        printf("\n===================================\n");
        printf("   STRING OPERATIONS MENU SYSTEM\n");
        printf("===================================\n");
        printf("1. Calculate String Length\n");
        printf("2. Copy String\n");
        printf("3. Concatenate Two Strings\n");
        printf("4. Compare Two Strings\n");
        printf("5. Reverse a String\n");
        printf("6. Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            flush_input();
            continue;
        }
        flush_input(); // Clear newline after numeric input

        switch (choice) {
            case 1:
                printf("\nEnter a string: ");
                fgets(str1, sizeof(str1), stdin);
                remove_newline(str1);
                printf("Length of the string: %lu\n", (unsigned long)strlen(str1));
                break;

            case 2:
                printf("\nEnter source string to copy: ");
                fgets(str1, sizeof(str1), stdin);
                remove_newline(str1);
                strcpy(str2, str1);
                printf("Source String: %s\n", str1);
                printf("Copied String: %s\n", str2);
                break;

            case 3:
                printf("\nEnter first string: ");
                fgets(str1, sizeof(str1), stdin);
                remove_newline(str1);
                printf("Enter second string to add: ");
                fgets(str2, sizeof(str2), stdin);
                remove_newline(str2);
                
                strcpy(result, str1);
                strcat(result, str2);
                printf("Concatenated Result: %s\n", result);
                break;

            case 4:
                printf("\nEnter first string: ");
                fgets(str1, sizeof(str1), stdin);
                remove_newline(str1);
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                remove_newline(str2);

                int cmp = strcmp(str1, str2);
                if (cmp == 0) {
                    printf("Both strings are identical.\n");
                } else if (cmp > 0) {
                    printf("First string matches lexicographically higher than second.\n");
                } else {
                    printf("Second string matches lexicographically higher than first.\n");
                }
                break;

            case 5:
                printf("\nEnter string to reverse: ");
                fgets(str1, sizeof(str1), stdin);
                remove_newline(str1);
                
                int len = strlen(str1);
                printf("Reversed String: ");
                for (int i = len - 1; i >= 0; i--) {
                    putchar(str1[i]);
                }
                printf("\n");
                break;

            case 6:
                printf("\nExiting program. Thank you!\n");
                break;

            default:
                printf("\nInvalid selection! Choose an option between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
