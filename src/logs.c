#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/logs.h"



int add_daily_log(const char *filename, DailyLog *entry) 
{
    FILE *f = fopen(filename, "a");
    if (f == NULL)
    {
        return 0;
    }

    //Writing one log: day month year mood sleep water
    DailyLog e = *entry;

    fprintf(f, "%d %d %d %d %.2f %d\n",
            e.day, e.month, e.year, e.mood, e.sleepHrs,e.waterGlasses);
    
    
    fclose(f);
    return 1;

}