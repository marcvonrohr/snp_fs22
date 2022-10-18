#include "header.h"

void aufgabe14() {
    printf("\nAufgabe 1.4\n");
    int a = 16; // any positive number

    int flippedA = a - 1;
    printf("0x%04X 0x%04X\n", a, flippedA);
    if (a > 0 && ((a & flippedA) == 0)) {
        printf("%d is a power of 2\n", a);
    }
}
