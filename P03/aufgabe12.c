#include "header.h"

void aufgabe12(){
    printf("\nAufgabe 1.2\n");
    int a = 3;
    int b = 4;
    printf("a: %d; b: %d\n", a, b);

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("a: %d; b: %d\n", a, b);
}


