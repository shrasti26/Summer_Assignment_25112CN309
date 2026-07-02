#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "contacts.txt"

// Structure to hold contact details
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

// Function prototypes
void addContact();
void displayContacts();
void searchContact();

int main() {
    int choice;

    while (1) {
        printf("\n=== CONTACT MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        // Read choice safely
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        getchar(); // Consume trailing newline character

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                printf("Thank you for using the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 4.\n");
        }
    }
    return 0;
}

// Function to add a contact to the file
void addContact() {
    FILE *fp = fopen(FILE_NAME, "a"); // Open in append mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Contact c;
    
    printf("\nEnter Name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = 0; // Remove newline character

    printf("Enter Phone Number: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = 0;

    printf("Enter Email: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = 0;

    // Save data separating fields with a unique separator (comma)
    fprintf(fp, "%s,%s,%s\n", c.name, c.phone, c.email);
    fclose(fp);

    printf("Contact added successfully!\n");
}

// Function to display all contacts from the file
void displayContacts() {
    FILE *fp = fopen(FILE_NAME, "r"); // Open in read mode
    if (fp == NULL) {
        printf("\nNo contacts found. Register a contact first!\n");
        return;
    }

    char line[150];
    int count = 1;

    printf("\n--- ALL CONTACTS ---\n");
    printf("%-5s %-25s %-15s %-30s\n", "S.No", "Name", "Phone", "Email");
    printf("----------------------------------------------------------------------\n");

    // Read file line by line
    while (fgets(line, sizeof(line), fp)) {
        char name[50], phone[20], email[50];
        
        // Parse comma-separated line entries
        char *token = strtok(line, ",");
        if (token != NULL) strcpy(name, token);
        
        token = strtok(NULL, ",");
        if (token != NULL) strcpy(phone, token);
        
        token = strtok(NULL, ",\n");
        if (token != NULL) strcpy(email, token);

        printf("%-5d %-25s %-15s %-30s\n", count++, name, phone, email);
    }

    fclose(fp);
}

// Function to search for a contact by name
void searchContact() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo contacts found to search!\n");
        return;
    }

    char searchName[50];
    printf("\nEnter the name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0;

    char line[150];
    int found = 0;

    while (fgets(line, sizeof(line), fp)) {
        char name[50], phone[20], email[50];
        
        // Parse the record
        char *token = strtok(line, ",");
        if (token != NULL) strcpy(name, token);
        
        token = strtok(NULL, ",");
        if (token != NULL) strcpy(phone, token);
        
        token = strtok(NULL, ",\n");
        if (token != NULL) strcpy(email, token);

        // Check for an exact substring match (case-sensitive)
        if (strstr(name, searchName) != NULL) {
            if (!found) {
                printf("\nMatch Found:\n");
                printf("%-25s %-15s %-30s\n", "Name", "Phone", "Email");
                printf("----------------------------------------------------------------------\n");
            }
            printf("%-25s %-15s %-30s\n", name, phone, email);
            found = 1;
        }
    }

    if (!found) {
        printf("No contact found matching '%s'.\n", searchName);
    }

    fclose(fp);
}
