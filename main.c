#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_MOVIES 3
#define NUM_SHOWTIMES 2
#define ROWS 5
#define COLS 10
#define COLOR_RESET   "\033[0m"
#define COLOR_BOLD_CYAN "\033[1;36m"
#define COLOR_GREEN   "\033[0;32m"
#define COLOR_YELLOW  "\033[0;33m"
void displayMenu();

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

int main() {
    int choice;
    while(1) {
        displayMenu();
        scanf("%d", &choice);
        if(choice == 7) {
            printf(COLOR_BOLD_CYAN "____Exiting system............\n" COLOR_RESET );
            break;
        }

    }


    return 0;
}
