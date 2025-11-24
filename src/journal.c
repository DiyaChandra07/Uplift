#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/journal.h"


char *read_line(FILE *f)
{
    static char buffer[600];

    if (fgets(buffer, sizeof(buffer), f) == NULL)
        return NULL;

    /*
    to remove newline. if \n is encountered it will 
    replace with end of string marker
    */
    for (int i = 0; buffer[i] != '\0'; i++) {
    if (buffer[i] == '\n') {
        buffer[i] = '\0';
        break;
    }
}

    return buffer;   
}

//adding a new journal entry

int add_journal_entry(const char *filename, int d, int y, int m, const char *text)
{
    FILE *f = fopen(filename, "a");
    if (f == 0)
    {
        return 0;
    }

    //structure of the journal entry
    fprintf(f, "## %02d/%02d/%04d\n", d, m, y); //date DD/MM/YYYY
    fprintf(f, "%s\n", text );  //entry
    fprintf(f,"----\n"); //seperator four dashes
    
    fclose(f);
    return 1;


}

//TO view the journal by date
int view_journal_by_date(const char *filename, int d, int m, int y)
{
    FILE *f = fopen(filename, "r");
    if (f == 0)
    {
        return 0;
    }


    char header [50];
    snprintf(header, sizeof(header),"## %02d/%02d/%04d", d,m,y);

    char *line = NULL;
    int flag = 0;

    //using read_line function to read line by line
    while ((line = read_line(f)) !=NULL)
    {
        if (strcmp(line, header) ==0)
        {
            printf("\nJournal entry written on %02d/%02d/%04d:\n", d,m,y);
            flag= 1;

            while ((line = read_line(f)) != NULL)
            {
                if (strncmp(line, "----",4)== 0)
                {
                    break;
                }
                printf("%s", line);
                
            }
            
            break;
        }
        
    }
    fclose(f);

    if (flag == 0)
    {
        printf("Sorry, No journal entry found for this date\n");

    }
    return flag;
}

