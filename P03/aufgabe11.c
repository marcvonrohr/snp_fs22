#include "header.h"

void aufgabe11(){
    // According to: https://stackoverflow.com/questions/47981/how-do-you-set-clear-and-toggle-a-single-bit
    printf("Aufgabe 1.1\n");
    unsigned int number = 0x75;
    unsigned int bit = 3; // bit at position 3

    printf("number = %i\n", number);
    // Setting a bit
    number |= 1UL << bit;
    printf("number = 0x%02X %i\n", number, number);
    // Clearing a bit
    bit = 1;
    number &= ~(1UL << bit);
    printf("number = 0x%02X %i\n", number, number);

    // Toggling a bit
    bit = 0;
    number ^= 1UL << bit;
    printf("number = 0x%02X %i\n", number, number);
}
