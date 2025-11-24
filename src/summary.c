#include <stdio.h>
#include <stdlib.h>

#include "../include/logs.h"
#include "../include/summary.h"

static int is_leap(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);

}

//to automatically count the seven days for weekly summary
static void next_day (int *d, int *m, int *y)
{
    int daysOfMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    if (is_leap(*y)) daysOfMonth[2] = 29;
    (*d)++;

    if (*d >daysOfMonth[*m])
    {
        *d = 1;
        (*m)++;
        if (*m >12)
        {
            *m =1;
            (*y)++;

        }
    }
}

//weekly summary
int weekly_summary(const char *logs_filename, int d, int m, int y) 
{
    float moodSum = 0;
    float sleepSum = 0;
    int waterSum = 0;
    int count = 0;
    
    printf("\n----- Weekly Summary -----\n");

    for (int i = 0; i< 7; i++)
    {
        size_t flag = 0;
        DailyLog *logs = find_logs_by_date(logs_filename, d,m,y, &flag);

        if (logs)
        {
            for (size_t j =0; j < flag; j++ )
            {
                moodSum += logs[j].mood;
                sleepSum += logs[j].sleepHrs;
                waterSum += logs[j].waterGlasses;

                count++;

            }
            free (logs);
        }

        next_day(&d,&m,&y);

    }

    if (count == 0)
    {
        printf("No data for this week. \n");
        return 0;
    }

    printf("Average Mood  : %.2f\n", moodSum  / count);
    printf("Average Sleep : %.2f\n", sleepSum / count);
    printf("Water (Total) : %d glasses\n", waterSum);

    return 1;

}



