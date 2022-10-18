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

#include "file_io.h"
#include "person.h"
#include "list.h"
//#include "person.c"
//#include "file_io.c"
//#include "list.c"

typedef enum {
    Insert, Remove, Show, Clear, End
} actions;

void end(int *running) {
    store_person_list();
    //printf("Program terminated");
    *running = 0;
}

char readChar() {
    char letter;
    int counter = 0;
    char *word = malloc(sizeof(char));
    while ((letter = getchar()) != '\n') {
        word[counter] = letter;
        counter++;
    }
    return word[0];
}

int readAction() {
    int actionIsValid = 0;
    char enteredValue;
    while (actionIsValid == 0) {
        printf("Bitte Aktion eingeben:");
        // ACHTUNG!!! führenden Blank nicht entfernen - Bufferproblem mit Enter
        enteredValue = readChar();
        switch (enteredValue) {
		case 'I': {
                	actionIsValid = 1;
                	return Insert;
		}
            	case 'R':{
                	actionIsValid = 1;
                	return Remove;
		}
            	case 'S':{
                	actionIsValid = 1;
                	return Show;
		}
            	case 'C':{
                	actionIsValid = 1;
               		return Clear;
		}
            	case 'E':{
			//printf("Terminating program");
                	actionIsValid = 1;
                	return End;
		}
	    	case 'B':{
			printf("Do a barrel roll");
			return 1;
		}
            	default:{
                	//printf("Der eingegebene Wert ist fehlerhaft.\n");
                	actionIsValid = 0;
		}
        }
    }
}



/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments...
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) there is an expression syntax error.
 */
int main(int argc, char* argv[])
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	node_t *anchor = list_init();
	load_person_list();
	int running = 1;
   	while (running) {
        	switch (readAction()) {
            		case Insert:
			{
				person_t *person = malloc(sizeof(person_t));
				person_read(person);
	                	list_insert(person);
	                	printf("Das Element wurde eingefugt\n");
        	       		break;
			}
            		case Remove:
			{
				person_t *personR = malloc(sizeof(person_t));
				person_read(personR);
				if (list_remove(personR) == 1) {
                    			printf("Element wurde nicht gefunden\n");
                		} else {
                    			printf("Element erfolgreich geloescht\n");
                		}
                		break;
			}
            		case Show:
                		list_show();
                		break;
            		case Clear:
                		list_clear();
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
