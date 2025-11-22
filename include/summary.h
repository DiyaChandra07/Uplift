#ifndef SUMMARY_H
#define SUMMARY_H

/* 

Weekly summary fromm a given date. computes:
    avg mood
    avg sleep
    total water consumed

*/

int weekly_summary(const char *logs_filename, int start_d, int start_m, int start_y);

#endif