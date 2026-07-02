#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

// Define the structure for a book
struct Book {
    int id;
    char title[100];
    char author[100];
    int is_issued; // 0 = Available, 1 = Issued
};

// Function prototypes
void addBook(struct Book library[], int *bookCount);
void displayBooks(const struct Book library[], int bookCount);
void searchBook(const struct Book library[], int bookCount);
void issueBook(struct Book library[], int bookCount);
void returnBook(struct Book library[], int bookCount);

int main() {
    struct Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n   MINI LIBRARY MANAGEMENT SYSTEM ");
        printf("\n=================================");
        printf("\n1. Add New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search for a Book");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit");
        printf("\n\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                searchBook(library, bookCount);
                break;
            case 4:
                issueBook(library, bookCount);
                break;
            case 5:
                returnBook(library, bookCount);
                break;
            case 6:
                printf("\nThank you for using the library system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}

// Function to add a book to the library
void addBook(struct Book library[], int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("\nLibrary is full! Cannot add more books.\n");
        return;
    }

    struct Book newBook;
    printf("\nEnter Unique Book ID (Integer): ");
    scanf("%d", &newBook.id);
    getchar(); // Clear trailing newline from buffer

    // Check if ID already exists
    for (int i = 0; i < *bookCount; i++) {
        if (library[i].id == newBook.id) {
            printf("\nError: A book with ID %d already exists!\n", newBook.id);
            return;
        }
    }

    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove newline character

    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove newline character

    newBook.is_issued = 0; // Default status is available

    library[*bookCount] = newBook;
    (*bookCount)++;

    printf("\nBook added successfully!\n");
}

// Function to display all books
void displayBooks(const struct Book library[], int bookCount) {
    if (bookCount == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }

    printf("\n----------------------------------------------------------------------------------");
    printf("\n%-10s %-35s %-25s %-10s", "Book ID", "Title", "Author", "Status");
    printf("\n----------------------------------------------------------------------------------");
    
    for (int i = 0; i < bookCount; i++) {
        printf("\n%-10d %-35s %-25s %-10s", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].is_issued ? "Issued" : "Available");
    }
    printf("\n----------------------------------------------------------------------------------\n");
}

// Function to search a book by ID or Title
void searchBook(const struct Book library[], int bookCount) {
    if (bookCount == 0) {
        printf("\nNo books to search.\n");
        return;
    }

    int choice;
    printf("\nSearch by:\n1. Book ID\n2. Book Title\nEnter choice (1-2): ");
    scanf("%d", &choice);
    getchar(); // Clear buffer

    if (choice == 1) {
        int searchId, found = 0;
        printf("Enter Book ID to search: ");
        scanf("%d", &searchId);

        for (int i = 0; i < bookCount; i++) {
            if (library[i].id == searchId) {
                printf("\nBook Found:\nID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n", 
                       library[i].id, library[i].title, library[i].author, 
                       library[i].is_issued ? "Issued" : "Available");
                found = 1;
                break;
            }
        }
        if (!found) printf("\nBook with ID %d not found.\n", searchId);

    } else if (choice == 2) {
        char searchTitle[100];
        int found = 0;
        printf("Enter Book Title to search: ");
        fgets(searchTitle, sizeof(searchTitle), stdin);
        searchTitle[strcspn(searchTitle, "\n")] = '\0';

        for (int i = 0; i < bookCount; i++) {
            // Case-sensitive exact match substring lookup
            if (strstr(library[i].title, searchTitle) != NULL) {
                printf("\nBook Found:\nID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n", 
                       library[i].id, library[i].title, library[i].author, 
                       library[i].is_issued ? "Issued" : "Available");
                found = 1;
            }
        }
        if (!found) printf("\nNo book found matching title: \"%s\"\n", searchTitle);
    } else {
        printf("\nInvalid choice.\n");
    }
}

// Function to issue a book
void issueBook(struct Book library[], int bookCount) {
    int id, found = 0;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            found = 1;
            if (library[i].is_issued == 1) {
                printf("\nSorry, this book is already issued to someone else.\n");
            } else {
                library[i].is_issued = 1;
                printf("\nBook successfully issued!\n");
            }
            break;
        }
    }
    if (!found) printf("\nBook ID not found.\n");
}

// Function to return a book
void returnBook(struct Book library[], int bookCount) {
    int id, found = 0;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            found = 1;
            if (library[i].is_issued == 0) {
                printf("\nThis book was not issued. It is already in the library.\n");
            } else {
                library[i].is_issued = 0;
                printf("\nBook successfully returned to the library!\n");
            }
            break;
        }
    }
    if (!found) printf("\nBook ID not found.\n");
}
