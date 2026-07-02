#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

// Function prototypes
void displayMenu();
void addStudent(int rollNumbers[], char names[][NAME_LENGTH], float marks[], int *count);
void displayStudents(const int rollNumbers[], const char names[][NAME_LENGTH], const float marks[], int count);
void searchStudent(const int rollNumbers[], const char names[][NAME_LENGTH], const float marks[], int count);

int main() {
    int rollNumbers[MAX_STUDENTS];
    char names[MAX_STUDENTS][NAME_LENGTH];
    float marks[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    printf("--- Welcome to Student Record Management System ---\n");

    while (1) {
        displayMenu();
        printf("Enter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1:
                addStudent(rollNumbers, names, marks, &studentCount);
                break;
            case 2:
                displayStudents(rollNumbers, names, marks, studentCount);
                break;
            case 3:
                searchStudent(rollNumbers, names, marks, studentCount);
                break;
            case 4:
                printf("Exiting system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select between 1 and 4.\n\n");
        }
    }
    return 0;
}

// Function to display the application menu
void displayMenu() {
    printf("\n====== MAIN MENU ======\n");
    printf("1. Add Student Record\n");
    printf("2. Display All Student Records\n");
    printf("3. Search Student by Roll Number\n");
    printf("4. Exit System\n");
    printf("=======================\n");
}

// Function to add a new student record using parallel arrays
void addStudent(int rollNumbers[], char names[][NAME_LENGTH], float marks[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nError: Database is full! Cannot add more students.\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &rollNumbers[*count]);
    getchar(); // Clear newline character left by scanf from input buffer

    printf("Enter Student Name: ");
    fgets(names[*count], NAME_LENGTH, stdin);
    names[*count][strcspn(names[*count], "\n")] = '\0'; // Remove trailing newline character

    printf("Enter Total Marks: ");
    scanf("%f", &marks[*count]);

    (*count)++; // Increment total student counter
    printf("Record added successfully!\n");
}

// Function to print all student records
void displayStudents(const int rollNumbers[], const char names[][NAME_LENGTH], const float marks[], int count) {
    if (count == 0) {
        printf("\nNo student records found in the system.\n");
        return;
    }

    printf("\n-------------------------------------------------\n");
    printf("%-10s %-25s %-10s\n", "Roll No", "Name", "Marks");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-10.2f\n", rollNumbers[i], names[i], marks[i]);
    }
    printf("-------------------------------------------------\n");
}

// Function to search for a specific student record by roll number
void searchStudent(const int rollNumbers[], const char names[][NAME_LENGTH], const float marks[], int count) {
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int searchRoll;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &searchRoll);

    for (int i = 0; i < count; i++) {
        if (rollNumbers[i] == searchRoll) {
            printf("\nRecord Found!\n");
            printf("Roll Number: %d\n", rollNumbers[i]);
            printf("Name       : %s\n", names[i]);
            printf("Marks      : %.2f\n", marks[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with Roll Number %d not found.\n", searchRoll);
    }
}
