#include <stdio.h>

int main() {
    // Initialize variables
    int default_pin = 1234;
    int entered_pin;
    int choice;
    float balance = 5000.0; // Initial balance
    float amount;
    int pin_attempts = 0;

    printf("=== Welcome to the ATM Simulator ===\n");

    // PIN Authentication (Maximum 3 attempts)
    while (pin_attempts < 3) {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &entered_pin);

        if (entered_pin == default_pin) {
            break; // PIN is correct, exit the validation loop
        } else {
            pin_attempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n\n", 3 - pin_attempts);
        }
    }

    // If card is blocked after 3 failed attempts
    if (pin_attempts == 3) {
        printf("Too many incorrect attempts. Your card is temporarily blocked.\n");
        return 0; // Terminate program
    }

    // Main ATM Menu Loop
    do {
        printf("\n----- ATM MENU -----\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Cash\n");
        printf("3. Withdraw Cash\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Check Balance
                printf("\nYour current balance is: $%.2f\n", balance);
                break;

            case 2:
                // Deposit Cash
                printf("\nEnter the amount to deposit: $");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("$%.2f deposited successfully.\n", amount);
                    printf("New balance: $%.2f\n", balance);
                } else {
                    printf("Invalid deposit amount.\n");
                }
                break;

            case 3:
                // Withdraw Cash
                printf("\nEnter the amount to withdraw: $");
                scanf("%f", &amount);
                if (amount > balance) {
                    printf("Transaction Failed! Insufficient balance.\n");
                } else if (amount <= 0) {
                    printf("Invalid withdrawal amount.\n");
                } else {
                    balance -= amount;
                    printf("$%.2f withdrawn successfully.\n", amount);
                    printf("Remaining balance: $%.2f\n", balance);
                }
                break;

            case 4:
                // Exit Menu
                printf("\nThank you for using our ATM service. Goodbye!\n");
                break;

            default:
                printf("\nInvalid selection. Please choose a valid menu option.\n");
        }
    } while (choice != 4);

    return 0;
}
