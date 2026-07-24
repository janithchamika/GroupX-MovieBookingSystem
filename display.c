#include <stdio.h>
#include "booking.h"


void viewShowtimes(Movie movies[]) {
    printf("\n========================================\n");
    printf("      AVAILABLE MOVIES & SHOWTIMES      \n");
    printf("========================================\n");

    for(int i = 0; i < NUM_MOVIES; i++) {
        printf("\nMovie %d: %s\n", movies[i].movieId, movies[i].title);
        printf("------------------------\n");
        for(int j = 0; j < NUM_SHOWTIMES; j++) {
            printf("  [%d] Showtime: %s\n", j + 1, movies[i].showtimes[j].time);
        }
    }
    printf("\n========================================\n");
}

void viewSeatMap(Showtime *showtime) {
    printf("\n======================================================\n");
    printf("                   SEAT MAP                           \n");
    printf("======================================================\n\n");

    printf("        1   2   3   4   5   6   7   8   9   10\n");
    printf("    -----------------------------------------\n");

    for (int r = 0; r < ROWS; r++) {
        char rowChar = 'A' + r;
        printf("Row %c |", rowChar);

        for (int c = 0; c < COLS; c++) {

            if (showtime->seats[r][c].isBooked == 1) {
                printf(" X |");
            } else {
                printf(" . |");
            }
        }


        if (r == 0 || r == 1) {
            printf("  <- Regular (Rs. 500)");
        } else if (r == 2 || r == 3) {
            printf("  <- Premium (Rs. 750)");
        } else if (r == 4) {
            printf("  <- VIP     (Rs. 1000)");
        }
        printf("\n");
        printf("    -----------------------------------------\n");
    }

    printf("\nLegend: [ . ] = Free Seat  |  [ X ] = Booked Seat\n");
    printf("======================================================\n");
}
