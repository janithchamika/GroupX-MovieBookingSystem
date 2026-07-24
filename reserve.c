#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "booking.h"

void bookSeat(Showtime *showtime) {
    char rowChar;
    int col;

    printf("\n===================================\n");
    printf("            BOOK A SEAT            \n");
    printf("===================================\n");

    printf("Enter Row (A - E): ");
    scanf(" %c", &rowChar);

    printf("Enter Seat Number (1 - 10): ");
    scanf("%d", &col);

    rowChar = toupper(rowChar);

    int row = rowChar - 'A';
    col = col - 1;


    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("\n Invalid Row or Seat Number! Please try again.\n");
        return;
    }


    if (showtime->seats[row][col].isBooked == 1) {
        printf("\n Seat %c%d is ALREADY BOOKED by %s!\n",
               rowChar, col + 1, showtime->seats[row][col].customerName);
        return;
    }


    showtime->seats[row][col].isBooked = 1;

    printf("Enter Customer Name: ");

    scanf(" %[^\n]", showtime->seats[row][col].customerName);


    float price = 500.00;

    showtime->seats[row][col].pricePaid = price;

    showtime->ticketsSold++;
    showtime->totalRevenue += price;

    printf("\n Success! Seat %c%d successfully booked for %s.\n",
           rowChar, col + 1, showtime->seats[row][col].customerName);
    printf(" Ticket Price: LKR %.2f\n", price);
}

void cancelBooking(Showtime *showtime) {
    char rowChar;
    int col;

    printf("\n===================================\n");
    printf("          CANCEL BOOKING           \n");
    printf("===================================\n");

    printf("Enter Row (A - E): ");
    scanf(" %c", &rowChar);

    printf("Enter Seat Number (1 - 10): ");
    scanf("%d", &col);

    rowChar = toupper(rowChar);
    int row = rowChar - 'A';
    col = col - 1;

    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("\n Invalid Row or Seat Number! Please try again.\n");
        return;
    }

    if (showtime->seats[row][col].isBooked == 0) {
        printf("\n Seat %c%d is NOT BOOKED yet. Cannot cancel!\n", rowChar, col + 1);
        return;
    }

    float refundedAmount = showtime->seats[row][col].pricePaid;

    showtime->totalRevenue -= refundedAmount;
    showtime->ticketsSold--;

    showtime->seats[row][col].isBooked = 0;
    showtime->seats[row][col].pricePaid = 0.0;
    strcpy(showtime->seats[row][col].customerName, "");

    printf("\n Success! Booking for Seat %c%d has been CANCELLED.\n", rowChar, col + 1);
    printf(" Refunded Amount: LKR %.2f\n", refundedAmount);
}
