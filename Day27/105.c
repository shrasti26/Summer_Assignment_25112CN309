#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Define the structure to hold student details
struct Student {
    int rollNumber;
    char name[50];
    float gpa;
};

// Global variables to track data
struct Student students[MAX_STUDENTS];
int studentCount = 0;

// Function declarations
void addStudent();
void displayStudents();
void searchStudent();

int main() {
    int choice;

    while (1) {
        // Display Menu
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add a new student record
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Database full! Cannot add more students.\n");
        return;
    }

    struct Student newStudent;

    printf("\nEnter Roll Number: ");
    scanf("%d", &newStudent.rollNumber);
    
    // Simple check to ensure Roll Number is unique
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == newStudent.rollNumber) {
            printf("Error: Roll Number already exists!\n");
            return;
        }
    }

    printf("Enter Name: ");
    getchar(); // Clear the newline character from the input buffer
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0'; // Remove trailing newline character

    printf("Enter GPA: ");
    scanf("%f", &newStudent.gpa);

    // Store the new student in the array
    students[studentCount] = newStudent;
    studentCount++;

    printf("Record added successfully!\n");
}

// Function to display all student records
void displayStudents() {
    if (studentCount == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n%-10s %-30s %-5s\n", "Roll No", "Name", "GPA");
    printf("------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-10d %-30s %-5.2f\n", students[i].rollNumber, students[i].name, students[i].gpa);
    }
}

// Function to search for a specific student
void searchStudent() {
    if (studentCount == 0) {
        printf("\nNo student records found to search.\n");
        return;
    }

    int targetRoll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &targetRoll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == targetRoll) {
            printf("\nRecord Found:\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name:        %s\n", students[i].name);
            printf("GPA:         %.2f\n", students[i].gpa);
            return;
        }
    }

    printf("Student with Roll Number %d not found.\n", targetRoll);
}
