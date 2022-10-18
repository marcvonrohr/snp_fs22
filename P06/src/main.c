/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab implementation
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NAME_LEN 20

typedef struct {
    char name[NAME_LEN];
    char first_name[NAME_LEN];
    unsigned int age;
} person_t;

typedef struct node {
    person_t content;        // in diesem Knoten gespeicherte Person
    struct node *next;           // Pointer auf den nächsten Knoten in der Liste
} node_t;

typedef enum {
    Insert, Remove, Show, Clear, End
} actions;

char *readString();

char readChar();

int readInt();

// Funktionen für Aktionen
int readAction();

void insert(node_t *anchor, person_t person);

int removee(node_t *anchor, person_t person);

void show(node_t *anchor);

void clear(node_t *anchor);

void end(int *running);

/**
 * @brief  Compares two persons in this sequence: 1st=name, 2nd=first_name, 3rd=age
 * @param  a [IN] const reference to 1st person in the comparison
 * @param  b [IN] const reference to 2nd person in the comparison
 * @return =0 if all record fields are the same
 *         >0 if all previous fields are the same, but for this field, a is greater
 *         <0 if all previous fields are the same, but for this field, b is greater
 * @remark strncmp() is used for producing the result of string field comparisons
 * @remark a->age – b->age is used for producing the result of age comparison
 */
int person_compare(const person_t *a, const person_t *b) {
    if ((int)strcmp(a->name, b->name) == 0 && (int)strcmp(a->first_name, b->first_name) == 0 && (a->age - b->age) == 0) {
        return 0;
    } else if (((int)strcmp(a->name, b->name) <= 0) || ((int)strcmp(a->name, b->name) <= 0 && (int)strcmp(a->first_name, b->first_name) <= 0) || ((int)strcmp(a->name, b->name) <= 0 && (int)strcmp(a->first_name, b->first_name) <= 0 && (a->age - b->age) < 0)) {
        return -1;
    } else {
        return 1;
    }
}

int readAction() {
    int actionIsValid = 0;
    char enteredValue;
    while (actionIsValid == 0) {
        printf("Bitte Aktion eingeben:");
        // ACHTUNG!!! führenden Blank nicht entfernen - Bufferproblem mit Enter
        enteredValue = readChar();
        switch (enteredValue) {
            case 'I':
                actionIsValid = 1;
                return Insert;
            case 'R':
                actionIsValid = 1;
                return Remove;
            case 'S':
                actionIsValid = 1;
                return Show;
            case 'C':
                actionIsValid = 1;
                return Clear;
            case 'E':
                actionIsValid = 1;
                return End;
            default:
                printf("Der eingegebene Wert ist fehlerhaft.\n");
                actionIsValid = 0;
        }
    }
}

person_t getPersonDetails() {
    char *nameValue;
    char *first_nameValue;
    int ageValue;
    printf("Bitte Name eingeben:");
    nameValue = readString();
    printf("Bitte Vorname eingeben:");
    first_nameValue = readString();
    printf("Bitte Alter eingeben:");
    ageValue = readInt();
    //printf("Name: %s\nVorname: %s\nAlter: %d\n", nameValue, first_nameValue, ageValue);
    person_t *newPerson = malloc(sizeof(person_t));
    strcpy(newPerson->first_name, first_nameValue);
    strcpy(newPerson->name, nameValue);
    newPerson->age = ageValue;
    //printf("Name: %s\nVorname: %s\nAlter: %d\n", newPerson->name, newPerson->first_name, newPerson->age);
    return *newPerson;
}

char *readString() {
    char letter;
    int counter = 0;
    char *word = malloc(NAME_LEN * sizeof(char));
    while (((letter = getchar()) != '\n') && (letter != EOF)) {
        word[counter] = letter;
        counter++;
    }
    word[counter] = '\0';
    return word;
}

int readInt() {
    int value = malloc(sizeof(int));
    char *intAsString = readString();
    value = atoi(intAsString);
    return value;
}

char readChar() {
    char letter;
    int counter = 0;
    char *word = malloc(sizeof(char));
    while ((letter = getchar()) != '\n' && letter != EOF) {
        word[counter] = letter;
        counter++;
    }
    return word[0];
}

void insert(node_t *anchor, person_t person) {
    int added = 0;
    node_t *currentNode = anchor->next;
    node_t *previousNode = anchor;
    while (added == 0) {
        if (person_compare(&person, &currentNode->content) < 0 || currentNode == anchor) {
            added = 1;
            node_t *newNode = malloc(sizeof(node_t));
            newNode->content = person;
            previousNode->next = newNode;
            newNode->next = currentNode;
        } else {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
}

int removee(node_t *anchor, person_t person) {
    int returnCode = 0;
    int endReached = 0;
    int removed = 0;
    node_t *currentNode = anchor->next;
    node_t *previousNode = anchor;
    while (removed == 0 && endReached == 0) {
        if(currentNode == anchor){
            returnCode = 1;
            endReached = 1;
        }
        else if (person_compare(&person, &currentNode->content) == 0) {
            removed = 1;
            previousNode->next = currentNode->next;
        } else {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
    return returnCode;
}

void show(node_t *anchor) {
    int endOfList = 0;
    int index = 0;
    if(anchor->next == anchor){
        printf("Die Liste ist leer\n");
    }
    else{
        node_t *currentNode = anchor->next;
        while (endOfList == 0) {
            printf("Listeneintrag %d\n", index);
            printf("Name: %s\nVorname: %s\nAlter: %d\n", currentNode->content.name, currentNode->content.first_name,currentNode->content.age);
            if (currentNode->next == anchor) {
                endOfList = 1;
            } else {
                currentNode = currentNode->next;
            }
            index++;
        }
    }
}

void clear(node_t *anchor) {
    anchor->next = anchor;
}

void end(int *running) {
    *running = 0;
}

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments...
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) there is an expression syntax error.
 */
int main(int argc, char *argv[]) {
    // BEGIN-STUDENTS-TO-ADD-CODE

    node_t *anchor = malloc(sizeof(node_t));
    anchor->next = anchor;
    clear(&anchor);

    // if (p1 > p2) { ... }
    //if (person_compare(&p1, &p2) > 0) { ... }

    int running = 1;
    while (running) {
        switch (readAction()) {
            case Insert:
                insert(anchor, getPersonDetails());
                printf("Das Element wurde eingefugt\n");
                break;
            case Remove:
                if (removee(anchor, getPersonDetails()) == 1) {
                    printf("Element wurde nicht gefunden\n");
                } else {
                    printf("Element erfolgreich geloescht\n");
                }
                break;
            case Show:
                show(anchor);
                break;
            case Clear:
                clear(anchor);
                printf("Die Liste wurde erfolgreich geleert\n");
                break;
            case End:
                end(&running);
                break;
            default:
                continue;
        }
    }

    // END-STUDENTS-TO-ADD-CODE
    return EXIT_SUCCESS;
}
