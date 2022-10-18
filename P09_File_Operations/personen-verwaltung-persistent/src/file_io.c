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
#include <errno.h>

#include "file_io.h"
#include "person.h"
#include "list.h"

void perror_and_exit(const char *context) { perror(context); exit(EXIT_FAILURE); } // das muss noch an einen anderen Ort, scia

// May divide your code in further functions
// BEGIN-STUDENTS-TO-ADD-CODE

// END-STUDENTS-TO-ADD-CODE

void store_person_list(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	FILE* file;
       	file = fopen(FILE_PATH, "w");
	if(!file){
		printf("Something went wrong opening the file: %s", strerror(errno));
	}
	else
	{
		/*
		person_t* firstPerson = list_getFirst();
		person_t* currentPerson = list_getFirst();
		char *currentPersonAsString = malloc(sizeof(char) * 128);

		do{
			person_to_csv_string(currentPerson, currentPersonAsString);
			fprintf(file, "%s", currentPersonAsString);
			currentPerson = list_getNext();
		} while(person_compare(currentPerson, firstPerson) != 0);
		*/
		
		person_t* currentPerson = list_getFirst();
        	char *currentPersonAsString = malloc(sizeof(char) * 128);

        	int listSize = list_size();
        	for(int i = 0; i < listSize; i++){
                	if(i != 0){
                        	currentPerson = list_getNext();
                	}
                	person_to_csv_string(currentPerson, currentPersonAsString);
        	        fprintf(file, "%s\n", currentPersonAsString);
	        }

		fclose(file);	
	}
	// END-STUDENTS-TO-ADD-CODE
}

void load_person_list(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	FILE* file;
	file = fopen(FILE_PATH, "r");
	if(!file){
		printf("Something went wrong. Classic C-program...");
	}
	else{
		char fileContent[128];
		while(fgets(fileContent, 128, file)){
			//puts(fileContent);
			person_t* newPerson = malloc(sizeof(person_t));
			person_from_csv_string(newPerson, fileContent);
			list_insert(newPerson);
		}
	}
	// END-STUDENTS-TO-ADD-CODE
}
