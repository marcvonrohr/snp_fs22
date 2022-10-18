#include <assert.h>
#include <string.h>
#include <stdio.h>

#include <stdlib.h>
#include <ctype.h>
#include "person.h"

int person_compare(const person_t *a, const person_t *b)
{
	//assert(a);
	//assert(b);
	/*
	int res = strncmp(a->name, b->name, NAME_LEN);
	if (res == 0) res = strncmp(a->first_name, b->first_name, NAME_LEN);
	if (res == 0) res = a->age - b->age;
	return res;
	*/

    	if ((int)strcmp(a->name, b->name) == 0 && (int)strcmp(a->first_name, b->first_name) == 0 && (a->age - b->age) == 0) {
        	return 0;
    	} else if (((int)strcmp(a->name, b->name) <= 0) || ((int)strcmp(a->name, b->name) <= 0 && (int)strcmp(a->first_name, b->first_name) <= 0) || ((int)strcmp(a->name, b->name) <= 0 && (int)strcmp(a->first_name, b->first_name) <= 0 && (a->age - b->age) < 0)) {
        	return -1;
    	} else {
        	return 1;
    	}
}

int person_read(person_t *p)
{
	assert(p);
	assert(NAME_LEN == 20);
	memset(p, 0, sizeof(person_t));  
 
	return scanf("%19s %19s %d", p->name, p->first_name, &(p->age)) == 3;
}

//operations for persistency lab


static const int max_len = 128; //!!!könnte man schöner lösen, scia

int person_to_csv_string(person_t* person, char* s)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	char ageAsString[max_len];
        snprintf(ageAsString, sizeof(ageAsString), "%d",person->age);
	char personAsString[max_len];
	strcpy(personAsString, person->name);
	strcat(personAsString, ";");
	strcat(personAsString, person->first_name);
	strcat(personAsString, ";");
	strcat(personAsString, ageAsString);
	strcpy(s, personAsString);
	

	/*	
	int sIndex = 0;
	char name[NAME_LEN];
	// Name abarbeiten
	int charIndex = 0;
	char currentChar = name[charIndex];
	charIndex++;
	while(charIndex < NAME_LEN && currentChar != '\0'){
		s[sIndex] = currentChar;
		currentChar = person->name[charIndex];
		charIndex++;
	}	
	// Firstname abrabeiten
	s[++sIndex] = ';';
	charIndex = 0;
	currentChar = person->first_name[charIndex];
	charIndex++;
	while(charIndex < NAME_LEN && currentChar != '\0'){
		s[sIndex] = currentChar;
		currentChar = person->first_name[charIndex];
		charIndex++;
	}
	// Age abarbeiten
	s[++sIndex] = ';';
        charIndex = 0;
	char ageAsString[NAME_LEN];
        //itoa(person->age, ageAsString);
	snprintf (ageAsString, sizeof(ageAsString), "%d",person->age); // print int 'n' into the char[] buffer
	currentChar = ageAsString[charIndex];
        charIndex++;
        while(charIndex < NAME_LEN && currentChar != '\0'){
                s[sIndex] = currentChar;
                currentChar = ageAsString[charIndex];
                charIndex++;
        }
	*/
	return 1;
	// END-STUDENTS-TO-ADD-CODE
}


void person_from_csv_string(person_t* person, char* s)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	int sIndex = 0;
	int nameIndex = 0;
	int first_nameIndex = 0;
	int ageIndex = 0;
	char currentChar = s[sIndex];
	char name[NAME_LEN];
	char first_name[NAME_LEN];
	char ageAsString[NAME_LEN];
	while(sIndex < max_len && currentChar != ';'){
		name[nameIndex] = currentChar;
		nameIndex++;
		sIndex++;
		currentChar = s[sIndex];
	}
	sIndex++;
	currentChar = s[sIndex];
	while(sIndex < max_len && currentChar != ';'){
		first_name[first_nameIndex] = currentChar;
                first_nameIndex++;
                sIndex++;
                currentChar = s[sIndex];
	}
	sIndex++;
        currentChar = s[sIndex];
	while(sIndex < max_len && currentChar != '\0'){
		ageAsString[ageIndex] = currentChar;
                ageIndex++;
                sIndex++;
                currentChar = s[sIndex];
        }
	strcpy(person->name, name);
	strcpy(person->first_name, first_name);
	person->age = atoi(ageAsString);
	// END-STUDENTS-TO-ADD-CODE
}



