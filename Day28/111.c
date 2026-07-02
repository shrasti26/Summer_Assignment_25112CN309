#include <stdio.h>
#include <string.h>
#define TOTAL_SEATS 10
int seats[TOTAL_SEATS] = {0}; 
void displaySeats();
void bookTicket();
void cancelTicket();

int main() {
    int choice;
    while (1) {
        // Main Menu
        printf("\n=== TICKET BOOKING SYSTEM ===\n");
        printf("1. View Available Seats\n");
        printf("2. Book a Ticket\n");
        printf("3. Cancel a Ticket\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                printf("Thank you for using the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}
void displaySeats() {
    printf("\n--- Seating Arrangement ---\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i] == 0) {
            printf("[ Seat %d : Available ]\n", i + 1);
        } else {
            printf("[ Seat %d : BOOKED ]\n", i + 1);
        }
    }
}
void bookTicket() {
    int seatNumber;
    printf("\nEnter the seat number you want to book (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNumber);
    if (seatNumber < 1 || seatNumber > TOTAL_SEATS) {
        printf("Invalid seat number! Choose between 1 and %d.\n", TOTAL_SEATS);
        return;
    }
    int index = seatNumber - 1; 

    if (seats[index] == 1) {
        printf("Sorry, Seat %d is already booked!\n", seatNumber);
    } else {
        seats[index] = 1; 
        printf("Success! Seat %d has been booked for you.\n", seatNumber);
    }
}
void cancelTicket() {
    int seatNumber;
    printf("\nEnter the seat number to cancel (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > TOTAL_SEATS) {
        printf("Invalid seat number!\n");
        return;
    }

    int index = seatNumber - 1;

    if (seats[index] == 0) {
        printf("Seat %d is already empty. Nothing to cancel.\n", seatNumber);
    } else {
        seats[index] = 0; 
        printf("Success! Your booking for Seat %d has been canceled.\n", seatNumber);
    }
}
