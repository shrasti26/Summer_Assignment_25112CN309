#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Define the structure for Employee details
struct Employee {
    int id;
    char name[50];
    float salary;
};

// Global variables to track data
struct Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

// Function prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();
void deleteEmployee();

int main() {
    int choice;

    while (1) {
        printf("\n=== Employee Management System ===\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                deleteEmployee();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}

// Function to add a new employee
void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Error: Database full. Cannot add more employees.\n");
        return;
    }

    struct Employee newEmp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &newEmp.id);

    // Check if ID already exists
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == newEmp.id) {
            printf("Error: An employee with ID %d already exists!\n", newEmp.id);
            return;
        }
    }

    printf("Enter Employee Name: ");
    // Clear input buffer and read string with spaces
    getchar(); 
    fgets(newEmp.name, sizeof(newEmp.name), stdin);
    newEmp.name[strcspn(newEmp.name, "\n")] = 0; // Remove trailing newline character

    printf("Enter Salary: ");
    scanf("%f", &newEmp.salary);

    // Store in array
    employees[employeeCount] = newEmp;
    employeeCount++;
    printf("Employee added successfully!\n");
}

// Function to display all employee records
void displayEmployees() {
    if (employeeCount == 0) {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\n%-10s %-30s %-10s\n", "ID", "Name", "Salary");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%-10d %-30s %-10.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
}

// Function to search an employee by their ID
void searchEmployee() {
    if (employeeCount == 0) {
        printf("\nNo employee records found.\n");
        return;
    }

    int searchId;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == searchId) {
            printf("\nEmployee Found:\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Salary: %.2f\n", employees[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", searchId);
}

// Function to delete an employee record by shifting array elements
void deleteEmployee() {
    if (employeeCount == 0) {
        printf("\nNo employee records found to delete.\n");
        return;
    }

    int deleteId;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == deleteId) {
            // Shift elements to the left to delete the item
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Employee record deleted successfully!\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", deleteId);
}
