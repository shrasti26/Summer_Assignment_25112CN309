#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Employee structure
typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;

// Function prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();
void modifyEmployee();
void deleteEmployee();

const char* FILE_NAME = "employees.dat";

int main() {
    int choice;

    while (1) {
        printf("\n=== MINI EMPLOYEE MANAGEMENT SYSTEM ===\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Modify Employee Record\n");
        printf("5. Delete Employee Record\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: modifyEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: 
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// 1. Add a new employee record to the file
void addEmployee() {
    FILE *file = fopen(FILE_NAME, "ab"); // Open in append-binary mode
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    getchar(); // Clear trailing newline character

    printf("Enter Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Remove newline character

    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0; // Remove newline

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(Employee), 1, file);
    fclose(file);
    printf("Employee record added successfully!\n");
}

// 2. Read and display all employee records
void displayEmployees() {
    FILE *file = fopen(FILE_NAME, "rb"); // Open in read-binary mode
    if (file == NULL) {
        printf("\nNo records found. Add an employee first!\n");
        return;
    }

    Employee emp;
    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("-----------------------------------------------------------------\n");

    while (fread(&emp, sizeof(Employee), 1, file) == 1) {
        printf("%-10d %-20s %-20s %-10.2f\n", emp.id, emp.name, emp.designation, emp.salary);
    }
    fclose(file);
}

// 3. Search for a specific employee by ID
void searchEmployee() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int searchId, found = 0;
    Employee emp;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    while (fread(&emp, sizeof(Employee), 1, file) == 1) {
        if (emp.id == searchId) {
            printf("\nRecord Found:\n");
            printf("ID: %d\nName: %s\nDesignation: %s\nSalary: %.2f\n", 
                   emp.id, emp.name, emp.designation, emp.salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", searchId);
    }
    fclose(file);
}

// 4. Modify an existing record matching an ID
void modifyEmployee() {
    FILE *file = fopen(FILE_NAME, "rb+"); // Open for reading and writing
    if (file == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int targetId, found = 0;
    Employee emp;

    printf("\nEnter Employee ID to modify: ");
    scanf("%d", &targetId);

    while (fread(&emp, sizeof(Employee), 1, file) == 1) {
        if (emp.id == targetId) {
            found = 1;
            getchar(); // Clear buffer

            printf("Enter New Name: ");
            fgets(emp.name, sizeof(emp.name), stdin);
            emp.name[strcspn(emp.name, "\n")] = 0;

            printf("Enter New Designation: ");
            fgets(emp.designation, sizeof(emp.designation), stdin);
            emp.designation[strcspn(emp.designation, "\n")] = 0;

            printf("Enter New Salary: ");
            scanf("%f", &emp.salary);

            // Move the file pointer back to the start of this specific record
            fseek(file, -sizeof(Employee), SEEK_CUR);
            fwrite(&emp, sizeof(Employee), 1, file);
            printf("Record updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", targetId);
    }
    fclose(file);
}

// 5. Delete a record using a temporary file transfer strategy
void deleteEmployee() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }

    int targetId, found = 0;
    Employee emp;

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &targetId);

    while (fread(&emp, sizeof(Employee), 1, file) == 1) {
        if (emp.id == targetId) {
            found = 1; // Skip writing this record to the temp file
        } else {
            fwrite(&emp, sizeof(Employee), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);             // Delete old storage file
        rename("temp.dat", FILE_NAME); // Rename temp file to main database
        printf("Record deleted successfully!\n");
    } else {
        remove("temp.dat"); // Clean up temp file if nothing was deleted
        printf("Employee with ID %d not found.\n", targetId);
    }
}
