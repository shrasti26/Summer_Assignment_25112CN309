#include <stdio.h>
#include <string.h>
struct BankAccount {
    int accountNumber;
    char holderName[50];
    float balance;
};

int main() {
    struct BankAccount account;
    int choice;
    float amount;
    int isAccountCreated = 0;

    printf("--- Welcome to the Simple Bank System ---\n");

    do {
        printf("\n1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Account Number: ");
                scanf("%d", &account.accountNumber);
                
                printf("Enter Account Holder Name: ");
                getchar(); 
                fgets(account.holderName, sizeof(account.holderName), stdin);
                account.holderName[strcspn(account.holderName, "\n")] = 0; // Remove trailing newline

                printf("Enter Initial Deposit: $");
                scanf("%f", &account.balance);

                isAccountCreated = 1;
                printf("\nAccount created successfully!\n");
                break;

            case 2:
                if (!isAccountCreated) {
                    printf("\nError: Please create an account first!\n");
                    break;
                }
                printf("\nEnter amount to deposit: $");
                scanf("%f", &amount);
                if (amount > 0) {
                    account.balance += amount;
                    printf("Successfully deposited $%.2f. New Balance: $%.2f\n", amount, account.balance);
                } else {
                    printf("Invalid amount! Deposit must be greater than zero.\n");
                }
                break;

            case 3:
                if (!isAccountCreated) {
                    printf("\nError: Please create an account first!\n");
                    break;
                }
                printf("\nEnter amount to withdraw: $");
                scanf("%f", &amount);
                if (amount > account.balance) {
                    printf("Transaction Failed: Insufficient balance!\n");
                } else if (amount <= 0) {
                    printf("Invalid amount! Withdrawal must be greater than zero.\n");
                } else {
                    account.balance -= amount;
                    printf("Successfully withdrew $%.2f. Remaining Balance: $%.2f\n", amount, account.balance);
                }
                break;

            case 4:
                if (!isAccountCreated) {
                    printf("\nError: Please create an account first!\n");
                    break;
                }
                printf("\n--- Account Details ---\n");
                printf("Account Number: %d\n", account.accountNumber);
                printf("Holder Name   : %s\n", account.holderName);
                printf("Current Balance: $%.2f\n", account.balance);
                break;

            case 5:
                printf("\nThank you for banking with us. Goodbye!\n");
                break;

            default:
                printf("\nInvalid selection! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}
