# GroupX-MovieBookingSystem
CSC 1031 Group Project - Movie Ticket Booking System. Built with C to manage seat bookings, apply discounts, and calculate revenue.

## Overview
This is a command-line Movie Ticket Booking System written in C for the CSC 1031 Group Project. It allows a theater to manage seat bookings, calculate ticket pricing with conditional discounts (Student, Senior Citizen, Group), and generate real-time revenue reports entirely in memory.

## Features
* **View Showtimes:** List all available movies and their showtimes.
* **View Seat Map:** Display the seat grid for a chosen showtime, indicating free (`.`) vs booked (`X`) seats, along with seat tiers (Regular, Premium, VIP).
* **Book a Seat:** Select a showtime and seat. The system checks availability, calculates the price based on the tier, applies valid discounts (Student - 10%, Senior - 20%, Group - 10%), and records the booking.
* **Cancel a Booking:** Free up a booked seat and remove its value from the revenue calculations.
* **Search Bookings:** Look up an existing booking by customer name or seat number to see the price paid.
* **Revenue Report:** Calculate and display the total tickets sold and total revenue generated per showtime.

## Project Structure
* `main.c` - Core logic, menu-driven interface, and module integration.
* `display.c` - Functions for rendering the seat map and UI elements.
* `reserve.c` - Logic for booking, validating, and canceling seats.
* `pricing.c` - Calculations for base prices and discount rules.
* `booking.h` - Shared data structures (structs) and function prototypes.

## Compilation Instructions
To compile the program, open your terminal or command prompt in the project directory and run the following GCC command:

```bash
gcc main.c display.c reserve.c pricing.c -o booking
```

## How to Run
After a successful compilation, run the executable file:

* **On Windows:**
  ```cmd
  booking.exe
  ```
  *(Or simply double-click the `booking.exe` file)*

* **On Linux / Mac:**
  ```bash
  ./booking
  ```