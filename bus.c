#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 50
#define NAME_LENGTH 50

// Structure to represent a seat
typedef struct {
    int seatNumber;
    int isOccupied;
    char passengerName[NAME_LENGTH];
} Seat;

// Array to hold all the seats
Seat seats[MAX_SEATS];

// Function prototypes
void initializeSeats();
void displayAvailableSeats();
void bookSeat();
void cancelSeat();

int main() {
    initializeSeats();
    int choice;

    do {
        printf("\n** BUS RESERVATION SYSTEM **\n");
        printf("1. Display available seats\n");
        printf("2. Book a seat\n");
        printf("3. Cancel seat reservation\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAvailableSeats();
                break;
            case 2:
                bookSeat();
                break;
            case 3:
                cancelSeat();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

// Initialize all seats as unoccupied
void initializeSeats() {
        for (int i = 0; i < MAX_SEATS; i++) {
        seats[i].seatNumber = i + 1;
        seats[i].isOccupied = 0;
        strcpy(seats[i].passengerName, "");
    }
}

// Display available seats
void displayAvailableSeats() {
    printf("\nAvailable Seats:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (!seats[i].isOccupied) {
            printf("Seat %d\n", seats[i].seatNumber);
        }
    }
}

// Book a seat
void bookSeat() {
    int seatNum;
    char name[NAME_LENGTH];

    printf("\nEnter seat number: ");
    scanf("%d", &seatNum);

    if (seatNum < 1 || seatNum > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }

    if (seats[seatNum - 1].isOccupied) {
        printf("Seat %d is already occupied.\n", seatNum);
    } else {
        printf("Enter passenger name: ");
        scanf("%s", name);

        seats[seatNum - 1].isOccupied = 1;
        strcpy(seats[seatNum - 1].passengerName, name);
        printf("Seat %d booked for %s.\n", seatNum, name);
    }
}

// Cancel seat reservation
void cancelSeat() {
    int seatNum;

    printf("\nEnter seat number to cancel reservation: ");
    scanf("%d", &seatNum);

    if (seatNum < 1 || seatNum > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }

    if (!seats[seatNum - 1].isOccupied) {
        printf("Seat %d is not occupied.\n", seatNum);
    } else {
        seats[seatNum - 1].isOccupied = 0;
        strcpy(seats[seatNum - 1].passengerName, "");
        printf("Reservation canceled for seat %d.\n", seatNum);
    }
}
