#include <stdio.h>

int main() {
    // Variable declarations
    char name[50];
    int rollNumber;
    float math, science, english;
    float totalMarks, percentage;
    char grade;

    // Header 
    printf("=========================================\n");
    printf("       MARKSHEET GENERATION SYSTEM       \n");
    printf("=========================================\n\n");

    // Taking student information
    printf("Enter Student Name: ");
    scanf(" %[^\n]s", name); // Reads string with spaces

    printf("Enter Roll Number: ");
    scanf("%d", &rollNumber);

    // Taking subject marks
    printf("Enter Marks for Math (0-100): ");
    scanf("%f", &math);

    printf("Enter Marks for Science (0-100): ");
    scanf("%f", &science);

    printf("Enter Marks for English (0-100): ");
    scanf("%f", &english);

    // Calculations
    totalMarks = math + science + english;
    percentage = (totalMarks / 300.0) * 100;

    // Grade Determination Logic [21]
    if (percentage >= 90) {
        grade = 'A';
    } else if (percentage >= 80) {
        grade = 'B';
    } else if (percentage >= 70) {
        grade = 'C';
    } else if (percentage >= 60) {
        grade = 'D';
    } else if (percentage >= 40) {
        grade = 'E';
    } else {
        grade = 'F'; // Fail [21]
    }

    // Displaying the generated report card format
    printf("\n=========================================\n");
    printf("               REPORT CARD               \n");
    printf("=========================================\n");
    printf(" Name       : %s\n", name);
    printf(" Roll No    : %d\n", rollNumber);
    printf("-----------------------------------------\n");
    printf(" SUBJECTS             MARKS OBTAINED     \n");
    printf("-----------------------------------------\n");
    printf(" Math                 : %.2f / 100\n", math);
    printf(" Science              : %.2f / 100\n", science);
    printf(" English              : %.2f / 100\n", english);
    printf("-----------------------------------------\n");
    printf(" Total Marks          : %.2f / 300\n", totalMarks);
    printf(" Percentage           : %.2f%%\n", percentage);
    printf(" Final Grade          : %c\n", grade);
    printf(" Status               : %s\n", (grade == 'F') ? "FAILED" : "PASSED");
    printf("=========================================\n");

    return 0;
}
