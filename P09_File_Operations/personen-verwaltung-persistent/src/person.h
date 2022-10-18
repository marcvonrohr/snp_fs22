#ifndef _PERSON_H_
#define _PERSON_H_

#include <stdio.h>

#define NAME_LEN 20

typedef struct {
    char name[20];
    char first_name[20];
    unsigned int age;
} person_t;

int person_compare(const person_t *a, const person_t *b);

int person_read(person_t *p);

int person_to_csv_string(person_t* person, char* s);

void person_from_csv_string(person_t* person, char* s);

#endif // _PERSON_H_
