#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/logs.h"


//adding daily log 
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


//Reading logs line by line
DailyLog *read_all_logs(const char *filename, size_t *total_logs)
{
        total_logs = 0;

        FILE *f = fopen(filename, "r");
        if (f == NULL)
        {
            return NULL;
        }

        DailyLog *arr = NULL;
        DailyLog temp;

        //Reading until EOF
        while (fscanf(f, "%d %d %d %d %f %d",
                        &temp.day, &temp.month, &temp.year,
                        &temp.mood,
                        &temp.sleepHrs,
                        &temp.waterGlasses)==6)
        {
            arr = realloc(arr,(*total_logs + 1) * sizeof(DailyLog));
            arr[*total_logs] = temp;
            (*total_logs)++;
        }

        fclose(f);
        return arr;



}