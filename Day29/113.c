#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    double num1, num2, result;

    do {
        // Displaying the main menu
        printf("\n=============================\n");
        printf("    MENU DRIVEN CALCULATOR   \n");
        printf("=============================\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // Terminate early if the user wants to exit
        if (choice == 5) {
            printf("\nExiting the calculator. Goodbye!\n");
            break;
        }

        // Validate choice before asking for numerical inputs
        if (choice < 1 || choice > 5) {
            printf("\nError: Invalid choice! Please select an option between 1 and 5.\n");
            continue;
        }

        // Prompt user for input values
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        // Process the selected mathematical operation
        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("\nResult: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 2:
                result = num1 - num2;
                printf("\nResult: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 3:
                result = num1 * num2;
                printf("\nResult: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 4:
                // Error checking for division by zero
                if (num2 == 0) {
                    printf("\nError: Mathematical exception! Division by zero is not allowed.\n");
                } else {
                    result = num1 / num2;
                    printf("\nResult: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;
            default:
                printf("\nUnexpected error occurred.\n");
        }

    } while (choice != 5);

    return 0;
}

