#include <stdio.h>
#include <stdlib.h>
#include "../include/summary.h"
#include "../include/logs.h"

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
int weekly_summary(const char *logs_filename, int d, int m, int y) {
    float moodSum = 0;
    float sleepSum = 0;
    int waterSum = 0;
    int count = 0;
    
    printf("\n----- Weekly Summary -----n");

    for (int i = 0)
