#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 50

// Structure to store employee and salary details
struct Employee {
    int id;
    char name[50];
    float basic_salary;
    float hra;          // House Rent Allowance
    float da;           // Dearness Allowance
    float pf;           // Provident Fund Deduction
    float gross_salary;
    float net_salary;
};

// Function prototypes
void addEmployees(struct Employee emp[], int *count);
void displaySalarySheet(struct Employee emp[], int count);
void searchEmployee(struct Employee emp[], int count);

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int employee_count = 0;
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    SALARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add Employee Records");
        printf("\n2. Display Salary Sheet");
        printf("\n3. Search Employee Slip by ID");
        printf("\n4. Exit");
        printf("\n\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployees(employees, &employee_count);
                break;
            case 2:
                displaySalarySheet(employees, employee_count);
                break;
            case 3:
                searchEmployee(employees, employee_count);
                break;
            case 4:
                printf("\nExiting system. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add employee details and compute salary breakups
void addEmployees(struct Employee emp[], int *count) {
    int num, i;
    printf("\nHow many employees do you want to add? ");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        if (*count >= MAX_EMPLOYEES) {
            printf("\nSystem database full!\n");
            return;
        }

        printf("\n--- Enter Details for Employee %d ---\n", *count + 1);
        printf("Enter Employee ID: ");
        scanf("%d", &emp[*count].id);
        
        printf("Enter Name (No spaces): ");
        scanf("%s", emp[*count].name);
        
        printf("Enter Basic Salary: ");
        scanf("%f", &emp[*count].basic_salary);

        // Salary Calculations (Standard Percentage Formulas)
        emp[*count].hra = 0.15 * emp[*count].basic_salary; // 15% HRA
        emp[*count].da = 0.20 * emp[*count].basic_salary;  // 20% DA
        emp[*count].pf = 0.12 * emp[*count].basic_salary;  // 12% PF Deduction

        // Gross Salary = Basic + Allowances
        emp[*count].gross_salary = emp[*count].basic_salary + emp[*count].hra + emp[*count].da;
        
        // Net Salary = Gross - Deductions
        emp[*count].net_salary = emp[*count].gross_salary - emp[*count].pf;

        (*count)++;
        printf("Employee record added successfully!\n");
    }
}

// Function to display the comprehensive salary sheet of all employees
void displaySalarySheet(struct Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo employee records found! Add records first.\n");
        return;
    }

    printf("\n====================================================================================\n");
    printf("%-5s %-15s %-12s %-8s %-8s %-8s %-12s %-12s\n", 
           "ID", "Name", "Basic", "HRA", "DA", "PF", "Gross", "Net Pay");
    printf("====================================================================================\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d %-15s %-12.2f %-8.2f %-8.2f %-8.2f %-12.2f %-12.2f\n",
               emp[i].id, emp[i].name, emp[i].basic_salary, 
               emp[i].hra, emp[i].da, emp[i].pf, 
               emp[i].gross_salary, emp[i].net_salary);
    }
    printf("====================================================================================\n");
}

// Function to search for an individual employee salary slip by ID
void searchEmployee(struct Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo employee records found!\n");
        return;
    }

    int search_id, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == search_id) {
            found = 1;
            printf("\n=====================================");
            printf("\n         SALARY SLIP GENERATED       ");
            printf("\n=====================================");
            printf("\nEmployee ID   : %d", emp[i].id);
            printf("\nEmployee Name : %s", emp[i].name);
            printf("\n-------------------------------------");
            printf("\nBasic Salary  : INR %.2f", emp[i].basic_salary);
            printf("\nHRA (15%%)     : INR %.2f", emp[i].hra);
            printf("\nDA (20%%)      : INR %.2f", emp[i].da);
            printf("\n-------------------------------------");
            printf("\nGross Salary  : INR %.2f", emp[i].gross_salary);
            printf("\nPF Deduction  : INR %.2f", emp[i].pf);
            printf("\n-------------------------------------");
            printf("\nNET TAKE-HOME : INR %.2f", emp[i].net_salary);
            printf("\n=====================================\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee Record with ID %d not found.\n", search_id);
    }
}
