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

DailyLog *find_logs_by_date (const char *filename, int d, int m, int y, size_t *total_logs)
{
    *total_logs = 0;
    size_t total = 0;

    DailyLog *all = read_all_logs(filename, &total);
    if (all == 0)
    {
        return NULL;
    }

    DailyLog *result = NULL;

    for (size_t i = 0; i<total; i++)
    {
        if (date_equal(&all[i], d,m,y))
        {
            result = realloc(result, (*total_logs + 1)* sizeof(DailyLog));
            result[*total_logs] = all[i];
            (*total_logs)++ ;
        }
    }

    free (all);
    return result;


}


int date_equal(const DailyLog *a, int d, int m, int y) 
{
    DailyLog date = *a;
    return (date.day == d && date.month == m && date.year == y);
}


int split_date(const char *s, int *d, int *m, int *y) 
{
    return sscanf(s, "%d/%d/%d", d, m, y) == 3;
}


void print_log(const DailyLog *log) 
{
    DailyLog entry = *log;
    printf("Date       : %02d/%02d/%04d \n", entry.day, entry.month, log->year);
    printf("Mood (1-5) : %d\n", entry.mood);
    printf("Sleep hrs  : %.2f\n", entry.sleepHrs);
    printf("Water (ml) : %d\n", entry.waterGlasses);
}