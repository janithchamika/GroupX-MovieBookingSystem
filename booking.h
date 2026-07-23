#ifndef BOOKING_H
#define BOOKING_H

#define NUM_MOVIES 3
#define NUM_SHOWTIMES 2
#define ROWS 5
#define COLS 10


typedef struct {
    int isBooked;
    char customerName[50];
    float pricePaid;
} Seat;


typedef struct {
    char time[20];
    Seat seats[ROWS][COLS];
    int ticketsSold;
    float totalRevenue;
} Showtime;


typedef struct {
    int movieId;
    char title[100];
    Showtime showtimes[NUM_SHOWTIMES];
} Movie;


void viewShowtimes(Movie movies[]);
void viewSeatMap(Showtime *showtime);

void bookSeat(Showtime *showtime);
void cancelBooking(Showtime *showtime);

float calculatePrice(char row, int discountType, int isGroup);
void searchBooking(Movie movies[]);
//void searchBooking(Movie movies[], char* searchName);
void viewRevenueReport(Movie movies[]);

#endif






