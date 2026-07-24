#include <ctype.h>
#include <stdio.h>
#include "booking.h"

float calculatePrice(char row, int discountType, int numTickets) {
    float basePrice = 0.0f;
    char upperRow = toupper(row);

    if (upperRow == 'A' || upperRow == 'B') {
        basePrice = 500.0f;
    } else if (upperRow == 'C' || upperRow == 'D') {
        basePrice = 750.0f;
    } else if (upperRow == 'E') {
        basePrice = 1000.0f;
    } else {
        return -1.0f;
    }

    float categoryDiscount = 0.0f;
    float groupDiscount = 0.0f;

    if (discountType == 1) {
        categoryDiscount = basePrice * 0.10f;
    } else if (discountType == 2) {
        categoryDiscount = basePrice * 0.20f;
    }

    if (numTickets >= 4) {
        groupDiscount = basePrice * 0.10f;
    }
    float finalPrice = basePrice - categoryDiscount - groupDiscount;

    if (finalPrice < 0.0f) {
        finalPrice = 0.0f;
    }
    return finalPrice;
}
