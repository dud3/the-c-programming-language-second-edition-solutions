#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* Handle leap years */
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int is_leap_year(year) 
{
    return (year % 4 == 0 && year % 100 == 0) || (year % 400 == 0);
}

void exit_on_error(int error, char *errorMessage)
{
    if(error == -1) {
        fprintf(stderr, "Error: %s\n", errorMessage);
        exit(EXIT_FAILURE); /* indicate failure.*/
    }
    
    free(errorMessage);
}

int day_of_year(int year, int month, int day)
{
    int i, leap;
    
    int error = 0;
    char *errorMessage = malloc(256);
    
    leap = is_leap_year(year);
    
    if(!(month >= 1 && month <= 12)) {
        error = -1;
        errorMessage = "Month out of range";
    }
    
    if(!(day >= 1 && day <= 31)) {
        error = -1;
        errorMessage = "Days out of range";
    }
    
    for(i = 1; i < month; i++)
        day += daytab[leap][i];
    
    exit_on_error(error, errorMessage);
    
    return day;
}

void month_day(int year, int yesterday, int *pmonth, int *pday)
{
    int i, leap;
    
    int error = 0;
    char *errorMessage = malloc(256);
    
    leap = is_leap_year(year);
    
    if(yesterday > 365) {
        error = -1;
        errorMessage = "Days out of range";
    }
    
    for(i = 1; yesterday > daytab[leap][i]; i++)
        yesterday -= daytab[leap][i];
        
    exit_on_error(error, errorMessage);
    
    *pmonth = i;
    *pday = yesterday;
}

int main()
{
    int a = day_of_year(1992, 2, 20);
    
    printf("Date to day: %d \n", a);
    
    int pmonth;
    int pday;
    
    month_day(1992, 51, &pmonth, &pday);
    printf("Day to date: month: %d day: %d\n", pmonth, pday);
    
    return 0;
}
