#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/**
 * AUFGABE 1
 */
static int aufgabe1(int argc, char *argv[]);

typedef enum {
    January = 1, February, March, April, Maye, June, July, August, September, October, November, December
} Month;

int gibIntWert(char *scope, int lower, int upper);

static int istSchaltjahr(int jahr);

static int tageProMonat(int jahr, int monat);

/**
 * AUFGABE 2
 */
static int aufgabe2(int argc, char *argv[]);

typedef enum {
    Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
} month_t;

typedef enum {
    Sun = 0, Mon, Tue, Wed, Thu, Fri, Sat
} weekday_t;

typedef struct {
    int year;
    int month;
    int day;
} date_t;

int parseDate(date_t date);

char *getStringForMonth(int index);

char *getStringForWeekday(int index);

int getWeekDayForDate(date_t date);

/**
 * MAIN Function
 */
int main(int argc, char *argv[]) {
    //aufgabe1(argc, *argv);
    aufgabe2(argc, *argv);
    return 0;
}

int aufgabe1(int argc, char *argv[]) {

    int monat, jahr;

    //  Monat einlesen und Bereich ueberpruefen
    monat = gibIntWert("Monat", 1, 12);
    jahr = gibIntWert("Jahr", 1600, 9999);

    //  Ausgabe zum Test
    printf("Monat: %d, Jahr: %d \n", monat, jahr);

    //  Ausgabe zum Test (hier mit dem ternaeren Operator "?:")
    printf("%d ist %s Schaltjahr\n", jahr, istSchaltjahr(jahr) ? "ein" : "kein");

    // Ausgabe
    printf("Der Monat %02d-%d hat %d Tage.\n", monat, jahr, tageProMonat(jahr, monat));

    return 0;
}

int aufgabe2(int argc, char *argv[]) {
    int year, month, day;
    printf("Bitte geben Sie das Datum ein (yyyy-mm-dd): ");
    scanf("%4d-%2d-%2d", &year, &month, &day);
    date_t date = {year, month, day};
    if (parseDate(date) == 0) {
        printf("\n%i-%i-%i is a %s", date.year, date.month, date.day, getStringForWeekday(getWeekDayForDate(date)));
    }
}

/**
 * AUFGABE 2
 */
int parseDate(date_t date) {
    int isValid = 1;
    if (((date.year <= 1582) && (date.month <= Oct) && (date.day < 15))) {
        fprintf(stderr, "Das erste gueltige Datum ist der 15.10.1582");
    } else if (date.year > 9999) {
        fprintf(stderr, "Das maximale Jahr ist 9999");
    } else if (date.month < 1 || date.month > 12) {
        fprintf(stderr, "Ein Monat muss zwischen 1 und 12 an");
    } else if (date.day < 1) {
        fprintf(stderr, "Der Tag muss positiv und nicht 0 sein");
    } else if (date.day > tageProMonat(date.year, date.month)) {
        fprintf(stderr, "Der Monat %s hat den Tag %i nicht", getStringForMonth(date.month), date.day);
    } else {
        printf("Gueltiges Datum");
        isValid = 0;
    }
    return isValid;
}

char *getStringForMonth(int index) {
    switch (index) {
        case Jan:
            return "Jan";
        case Feb:
            return "Feb";
        case Mar:
            return "Mar";
        case Apr:
            return "Apr";
        case May:
            return "May";
        case Jun:
            return "Jun";
        case Jul:
            return "Jul";
        case Aug:
            return "Aug";
        case Sep:
            return "Sep";
        case Oct:
            return "Oct";
        case Nov:
            return "Nov";
        case Dec:
            return "Dec";
    }
}

char *getStringForWeekday(int index) {
    switch (index) {
        case Sun:
            return "Sun";
        case Mon:
            return "Mon";
        case Tue:
            return "Tue";
        case Wed:
            return "Wed";
        case Thu:
            return "Thu";
        case Fri:
            return "Fri";
        case Sat:
            return "Sat";
    }
}

int getWeekDayForDate(date_t date) {
    int weekday  = (date.day += date.month < 3 ? date.year-- : date.year - 2, 23*date.month/9 + date.day + 4 + date.year/4- date.year/100 + date.year/400)%7;
    return weekday;
}

/**
 * AUFGABE 1
 */
int gibIntWert(char *scope, int lower, int upper) {
    int inputIsValid = 1;
    int input;
    while (inputIsValid == 1) {
        if (scope == "Monat") {
            printf("Bitte geben Sie den Monat ein:");
        } else {
            printf("Bitte geben Sie das Jahr ein:");
        }
        scanf("%i", &input);
        if (input < lower || input > upper) {
            printf("Der Wert muss zwischen %i und %i sein\n", lower, upper);
        } else {
            inputIsValid = 0;
            return input;
        }
    }
}

static int istSchaltjahr(int jahr) {
    if (jahr % 400 == 0) {
        return 1;
    } else if (jahr % 4 == 0 && jahr % 100 != 0) {
        return 1;
    } else {
        return 0;
    }
}

static int tageProMonat(int jahr, int monat) {
    if (istSchaltjahr(jahr) == 1 && monat == February) {
        return 29;
    } else {
        switch (monat) {
            case February:
                return 28;
            case April:
            case June:
            case September:
            case November:
                return 30;
            default:
                return 31;
        }
    }
}