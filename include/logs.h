#ifndef LOGS_H
#define LOGS_H

#include <stdio.h>

/*

Stucture to store one day's wellness data

fields: 
    day, month, year (date)
    mood (1-5)
    sleepHrs (hours slept in float)
    waterGlasses (glasses of water consumed)
    
*/

typedef struct DailyLog
{
    int day;
    int month;
    int year;
    int mood;
    float sleepHrs;
    int waterGlasses;

} ;

/* 

Declaring functionf for logs.c

*/

int add_daily_log(const char *filename, DailyLog *entry);
DailyLog *read_all_logs(const char *filename, size_t *total_logs);
DailyLog *find_logs_by_date (const char *filename, int d, int m, int y, size_t *total_logs);

int date_equal (const DailyLog *a, int d, int m, int y);
int split_date (const char *s, int *d, int *m, int *y);
void print_log(const DailyLog *log);

#endif