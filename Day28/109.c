#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100


struct Book {
    int id;
    char title[100];
    char author[100];
};

int main() {
    struct Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    while (1) {
        printf("\n=== Library Management System ===\n");
        printf("1. Add a Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1: 
                if (bookCount >= MAX_BOOKS) {
                    printf("Library is full! Cannot add more books.\n");
                    break;
                }
                
                printf("\nEnter Book ID (Integer): ");
                scanf("%d", &library[bookCount].id);
                while (getchar() != '\n'); 

                printf("Enter Book Title: ");
                fgets(library[bookCount].title, sizeof(library[bookCount].title), stdin);
                library[bookCount].title[strcspn(library[bookCount].title, "\n")] = '\0';

                printf("Enter Author Name: ");
                fgets(library[bookCount].author, sizeof(library[bookCount].author), stdin);
                library[bookCount].author[strcspn(library[bookCount].author, "\n")] = '\0'; 

                bookCount++;
                printf("Book added successfully!\n");
                break;

            case 2: // Display All Books
                if (bookCount == 0) {
                    printf("\nThe library is completely empty.\n");
                    break;
                }
                printf("\n--- Book Collection ---\n");
                printf("%-10s %-30s %-30s\n", "ID", "Title", "Author");
                for (int i = 0; i < bookCount; i++) {
                    printf("%-10d %-30s %-30s\n", library[i].id, library[i].title, library[i].author);
                }
                break;

            case 3: // Search Book by ID
                if (bookCount == 0) {
                    printf("\nThe library is empty. Nothing to search.\n");
                    break;
                }
                int searchId;
                int found = 0;
                printf("\nEnter the Book ID to search: ");
                scanf("%d", &searchId);

                for (int i = 0; i < bookCount; i++) {
                    if (library[i].id == searchId) {
                        printf("\nBook Found!\n");
                        printf("ID: %d\n", library[i].id);
                        printf("Title: %s\n", library[i].title);
                        printf("Author: %s\n", library[i].author);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("No book found with ID %d.\n", searchId);
                }
                break;

            case 4: // Exit
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option! Please pick a number between 1 and 4.\n");
        }
    }
    return 0;
}
