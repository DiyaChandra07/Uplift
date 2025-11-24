#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/logs.h"
#include "../include/journal.h"
#include "../include/summary.h"

#define LOG_FILE "logs.txt"
#define JOURNAL_FILE "journal.txt"

/*
to flush out the leftover characters from input buffer after scanf
*/
void flush_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

//asking user to enter a date
void prompt_date(int *d, int *m,int *y) {
    char buf[50];

    while (1) {
        printf("Date (DD/MM/YYYY): ");

        if (fgets(buf, sizeof(buf), stdin) && split_date(buf, d, m, y))
            break;

        printf("Invalid date format. Try again.\n");
    }
}


//adding a doily log

void add_daily_log()
{
    DailyLog log;

    prompt_date(&log.day, &log.month, &log.year);

    printf("Mood (1-5): ");
    scanf("%d", &log.sleepHrs);
    printf("Sleep Hours: ");
    scanf("%d",&log.sleepHrs);
    printf("Water (glasses): ");
    scanf("%d",&log.waterGlasses);

    flush_stdin();

    add_daily_log(LOG_FILE, &log);

    printf("Daily log added successfully.\n");

}

//to make journal entries in multiple line till END is typed

void add_journal()
{
    int d;
    int m;
    int y;

    prompt_date(&d,&m,&y);

    printf("Please write your journal! (type END once you are done): \n");

    char journal[3000] = "";
    char line[500];

    while (fgets(line, sizeof(line), stdin))
    {
        if (strcmp(line, "END\n") ==0)
        {
            break;
        }
        strcat(journal, line);
    }

    add_journal_entry(JOURNAL_FILE, d,m, y, journal);

    pritnf("Journal entry saved. Have a great day!");
}

//printing logs of specific day entered by user
void print_logs()
{
    int d;
    int m;
    int y;

    prompt_date (&d, &m, &y);

    size_t count;
    DailyLog *result = find_logs_by_date(LOG_FILE, d, m, y, &count);

    if (result==0 || count==0)
    {
        printf("Sorry no logs found..\n"); 
    }

    printf("\nLogs for %02d/%02d/%04d: \n",d,m,y);

    for (size_t i=0; i<count; i++)
    {
        print_log(&result[i]);
        prtinf("-----------------------\n");
    }
    free (result);

}

//view journal for given date
void view_journal()
{
    int d;
    int m;
    int y;

    prompt_date (&d, &m, &y);
    view_journal_by_date(JOURNAL_FILE, d,m,y);
}


//weekly summary
void summary()
{
    int d;
    int m;
    int y;
    prompt_date (&d, &m, &y);

    weekly_summary(LOG_FILE, d,m,y);
}

//main menue loop

int main()
{
    while (1)
    {
        printf("\n\n----- UpLift: Daily Wellness Tracker -----\n\n");
        printf("\tWelcome to Uplift!\n\tYour space to reflect, track, and grow.\n");
        printf("1. Add Daily Log\n");
        printf("2. Add Journal Entry\n");
        printf("3. View Logs by Date\n");
        printf("4. View Journal by Date\n");
        printf("5. Weekly Summary\n");
        printf("6. Exit\n");
        printf("Please choose the function you would like to perform: ");

        int choice;
        scanf("%d", &choice);
        flush_stdin();

        switch (choice) 
        {
            case 1: add_daily_log(); break;
            case 2: add_journal(); break;
            case 3: print_logs(); break;
            case 4: view_journal(); break;
            case 5: summary(); break;
            case 6: printf("Goodbye! Keep moving forward.\n"); return 0;
            default: printf("Invalid choice.. please try again.\n");
        }
    }
}
