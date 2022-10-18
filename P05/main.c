#include <stdio.h>
#include <string.h>
#include <ctype.h>

void bubbleSort(char words[]);

void printArray(char words[10][20]);

void bubbleSort(char words[]) {
    for (int k = sizeof(words) - 1; k > 0; k--) {
        for (int i = 0; i < k; i++) {
            if (strcmp(words[i], words[i + 1]) == 1) {
                char *temp = words[i];
                words[i] = words[i + 1];
                words[i + 1] = temp;
            }
        }
    }
}

void printArray(char words[10][20]) {
    printf("The Array elements are:\n");
    for (int i = 0; i < sizeof(words); i++) {
        for (int j = 0; j < sizeof(words[10]); j++) {
            printf("%c ", words[i][j]);
        }
        printf("\n"); // new line
    }
}

int main() {
    char words[10][20];
    int zCounter = 0;
    for (int i = 0; i < 10; i++) {
        printf("Please enter Word %i", i + 1);
        char letter;
        int counter = 0;
        char word[20];
        while (((letter = getchar()) != '\n') && (letter != EOF) && zCounter < 3) {
            //letter = toupper(letter);
            if (letter == 'Z') {
                if (counter == 0 || (zCounter == 1 && counter == 1) || (zCounter == 2 && counter == 2)) {
                    zCounter++;
                }
            }
            if (counter > 20) {
                printf("Word too large");
                return 1;
            }
            word[counter] = letter;
            counter++;
        }
        for (int k = 0; k <= i; k++) {
            if (strcmp(word, words[k]) == 0) {
                printf("Word is identical and will be ignored\n");
                // Countervariable für i dekrementieren damit keine Lücken im Array entstehen
                i--;
            } else {
                if (zCounter != 3) {
                    for (int j = 0; j < counter; j++) {
                        words[i][j] = word[j];
                    }
                }
            }
        }
        if (zCounter >= 3) {
            i = 10;
        }
    }
    printf("test");
    printArray(words);
    bubbleSort(words);
    printArray(words);
    return 0;
}
