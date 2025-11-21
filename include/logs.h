#ifndef LOGS_H
#define LOGS_H

#include <stdio.h>

/*Stucture to store one day's wellness data

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