#include <stdio.h>
#include "stdlib.h"

void charAndWordCounter() {
    int chCounter = 0;
    int wordCounter = 0;
    int ch;
    printf("Enter your input string:");
    while ((ch = getchar()) != '\n') {
        if (ch != '\t' && ch != ' ') {
            chCounter++;
        } else {
            wordCounter++;
        }
    }
    if (wordCounter != 0) {
        wordCounter++;
    }
    printf("chCount: %i\twordCount: %i", chCounter, wordCounter);
}

void convertCHFtoBTC() {
    const int NUM_ROWS = 8;
    int chfValue = 200;
    double rate;
    int i;

    printf("Enter conversion rate (1.00 BTC -> CHF):");
    scanf("%lf", &rate);
    for (i = 1; i <= NUM_ROWS; i++) {
        double btcValue = i / rate;
        printf("%i\t<-->\t%f \n", chfValue, btcValue);
        chfValue = chfValue * 2;
    }
}

int main() {
    // Aufgabe 02
    //printf("Hello, World!\n");
    // Aufgabe 03
    //convertCHFtoBTC();
    // Aufgabe 04
    charAndWordCounter();
    return 0;
}