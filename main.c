#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "booking.h"

#define COLOR_RED "\033[0;31m"
#define COLOR_RESET   "\033[0m"
#define COLOR_BOLD_CYAN "\033[1;36m"
#define COLOR_GREEN   "\033[0;32m"
#define COLOR_YELLOW  "\033[0;33m"

void displayMenu() {
    printf("\n" COLOR_BOLD_CYAN "------****** Movie Ticket Booking System ******------" COLOR_RESET "\n\n");

    printf(COLOR_GREEN);
    printf("1. View Showtimes\n");
    printf("2. View Seat Map\n");
    printf("3. Book a Seat\n");
    printf("4. Cancel a Booking\n");
    printf("5. Search Booking\n");
    printf("6. View Revenue Report\n");
    printf("7. Exit\n\n");
    printf(COLOR_RESET);
    printf(COLOR_YELLOW "Enter your choice: " COLOR_RESET);
}

void searchBooking(Movie movies[]) {
    int searchType;
    printf("\n" COLOR_BOLD_CYAN "--- Search Booking ---" COLOR_RESET "\n");
    printf("1. Search by Customer Name\n");
    printf("2. Search by Seat Number\n");
    printf("Enter your choice: ");
    scanf("%d", &searchType);

    int found = 0;

    if (searchType == 1) {
        char searchName[50];
        printf("Enter Customer Name: ");
        scanf(" %[^\n]", searchName);


        for (int i = 0; i < NUM_MOVIES; i++) {
            for (int j = 0; j < NUM_SHOWTIMES; j++) {
                for (int r = 0; r < ROWS; r++) {
                    for (int c = 0; c < COLS; c++) {
                        if (movies[i].showtimes[j].seats[r][c].isBooked == 1) {

                            if (strcmp(movies[i].showtimes[j].seats[r][c].customerName, searchName) == 0) {
                                printf("\n" COLOR_GREEN "Booking Found!" COLOR_RESET "\n");
                                printf("Movie: %s\n", movies[i].title);
                                printf("Showtime: %s\n", movies[i].showtimes[j].time);
                                printf("Seat: %c%d\n", 'A' + r, c + 1);
                                printf("Price Paid: Rs. %.2f\n", movies[i].showtimes[j].seats[r][c].pricePaid);
                                found = 1;
                            }
                        }
                    }
                }
            }
        }
    } else if (searchType == 2) {
        char searchRow;
        int searchCol;
        printf("Enter Seat Row (A-E): ");
        scanf(" %c", &searchRow);
        printf("Enter Seat Number (1-10): ");
        scanf("%d", &searchCol);

        searchRow = toupper(searchRow);
        int r = searchRow - 'A';
        int c = searchCol - 1;

        if (r >= 0 && r < ROWS && c >= 0 && c < COLS) {
            for (int i = 0; i < NUM_MOVIES; i++) {
                for (int j = 0; j < NUM_SHOWTIMES; j++) {
                     if (movies[i].showtimes[j].seats[r][c].isBooked == 1) {
                          printf("\n" COLOR_GREEN "Booking Found in %s (%s)!" COLOR_RESET "\n", movies[i].title, movies[i].showtimes[j].time);
                          printf("Customer Name: %s\n", movies[i].showtimes[j].seats[r][c].customerName);
                          printf("Price Paid: Rs. %.2f\n", movies[i].showtimes[j].seats[r][c].pricePaid);
                          found = 1;
                     }
                }
            }
        } else {
             printf(COLOR_RED "Invalid seat details.\n" COLOR_RESET);
             return;
        }
    } else {
        printf(COLOR_RED "Invalid search type.\n" COLOR_RESET);
        return;
    }

    if (!found) {
        printf(COLOR_YELLOW "\nNo bookings found matching your criteria.\n" COLOR_RESET);
    }
}
void viewRevenueReport(Movie movies[]) {
    printf("\n" COLOR_BOLD_CYAN "--- Revenue Report ---" COLOR_RESET "\n");
    int totalTickets = 0;
    float totalRevenue = 0.0;

    for (int i = 0; i < NUM_MOVIES; i++) {
        printf(COLOR_YELLOW "\nMovie: %s" COLOR_RESET "\n", movies[i].title);
        for (int j = 0; j < NUM_SHOWTIMES; j++) {
            printf("  Showtime: %s\n", movies[i].showtimes[j].time);
            printf("  Tickets Sold: %d\n", movies[i].showtimes[j].ticketsSold);
            printf("  Revenue: Rs. %.2f\n", movies[i].showtimes[j].totalRevenue);


            totalTickets += movies[i].showtimes[j].ticketsSold;
            totalRevenue += movies[i].showtimes[j].totalRevenue;
        }
    }

    printf("\n" COLOR_GREEN "===================================" COLOR_RESET "\n");
    printf("Total Tickets Sold (All Movies): %d\n", totalTickets);
    printf("Total Revenue (All Movies): Rs. %.2f\n", totalRevenue);
    printf(COLOR_GREEN "===================================" COLOR_RESET "\n");
}

void initMovies(Movie movies[]) {
    for(int i = 0; i < NUM_MOVIES; i++) {
        movies[i].movieId = i + 1;
        sprintf(movies[i].title, "Movie %d", i + 1);

        for(int j = 0; j < NUM_SHOWTIMES; j++) {
            sprintf(movies[i].showtimes[j].time, "1%d:00 PM", j + 4);
            movies[i].showtimes[j].ticketsSold = 0;
            movies[i].showtimes[j].totalRevenue = 0.0;


            for(int r = 0; r < ROWS; r++) {
                for(int c = 0; c < COLS; c++) {
                    movies[i].showtimes[j].seats[r][c].isBooked = 0;
                }
            }
        }
    }
}

int main() {

    Movie movies[NUM_MOVIES];
    initMovies(movies);

    int choice;

    while(1) {
        displayMenu();


        if (scanf("%d", &choice) != 1) {
            printf(COLOR_YELLOW "\nInvalid input! Please enter a number from 1 to 7.\n" COLOR_RESET);
            while (getchar() != '\n');
            continue;
        }


        switch(choice) {
            case 1:
                viewShowtimes(movies);
                break;
            case 2:
               int mIndex, sIndex;
                printf("Enter Movie Number (1-3): ");
                scanf("%d", &mIndex);
                printf("Enter Showtime Number (1-2): ");
                scanf("%d", &sIndex);

                if(mIndex >= 1 && mIndex <= NUM_MOVIES && sIndex >= 1 && sIndex <= NUM_SHOWTIMES) {
                    viewSeatMap(&movies[mIndex - 1].showtimes[sIndex - 1]);
                } else {
                    printf(COLOR_RED "Invalid Movie or Showtime selection.\n" COLOR_RESET);
                }
                break;

            case 3: {
                int mIndex, sIndex;
                printf("Enter Movie Number (1-3): ");
                scanf("%d", &mIndex);
                printf("Enter Showtime Number (1-2): ");
                scanf("%d", &sIndex);


                if(mIndex >= 1 && mIndex <= NUM_MOVIES && sIndex >= 1 && sIndex <= NUM_SHOWTIMES) {
                    bookSeat(&movies[mIndex - 1].showtimes[sIndex - 1]);
                } else {
                    printf("Invalid Movie or Showtime selection.\n");
                }
                break;
                }
            case 4: {
                int mIndex, sIndex;
                printf("Enter Movie Number (1-3): ");
                scanf("%d", &mIndex);
                printf("Enter Showtime Number (1-2): ");
                scanf("%d", &sIndex);

                if(mIndex >= 1 && mIndex <= NUM_MOVIES && sIndex >= 1 && sIndex <= NUM_SHOWTIMES) {
                    cancelBooking(&movies[mIndex - 1].showtimes[sIndex - 1]);
                } else {
                    printf("Invalid Movie or Showtime selection.\n");
                }
                break;
                }
            case 5:
                searchBooking(movies);
                break;
            case 6:
                viewRevenueReport(movies);
                break;
                break;
            case 7:
                printf(COLOR_BOLD_CYAN "\n____Exiting system............\n" COLOR_RESET );
                return 0;
            default:
                printf(COLOR_YELLOW "\nInvalid choice! Please select an option between 1 and 7.\n" COLOR_RESET);
        }
    }

    return 0;
}
