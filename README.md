# Uplift – Daily Wellness Tracker

A lightweight C program to track mood, sleep, water intake, and personal journals.


## Overview

**Uplift is a simple, offline wellness-tracking system developed in C.**

It allows users to:

    1.Log daily mood (1–5)

    2.Record sleep hours

    3.Track water consumption

    4.Write personal journal entries

    5.Retrieve logs and journals by date

    6.View weekly summaries with averages

**The project focuses on implementing core C concepts such as:**

    File handling
    
    Structures
    
    Dynamic memory allocation
    
    Functions
    
    String processing
    
    Searching and filtering
    

## Project Structure

/
│-- src/          (All .c files)
│-- include/      (All .h files)
│-- docs/         (Project report, flowcharts, diagrams)
│-- assets/       (Screenshots)
│-- README.md     (Project overview)
│-- uplift        (sample input file)
│-- journal.txt   (sample input file)
└── logs.txt      (sample input file)

## Features


### Daily Wellness Logging
Stores date-wise entries containing:

Mood rating

Sleep duration

Water consumption

Saved in logs.txt.

### Journal Module

Add personal journal entries

Entries saved in plain text in journal.txt

Each entry stored with date header and separator

### Date-wise Retrieval

Retrieve and print:

Logs for a selected date

Journal entries for a selected date

### Weekly Summary

Given a start date, the program calculates:

Average mood

Average sleep

Total water consumption

The function automatically moves across next 7 days (including month and year changes).

## Compilation Instructions

From the project root directory, run:

**gcc src/*.c -Iinclude -o uplift**

To execute:

**./uplift**

## How It Works

**Add Daily Log**

Prompts user for:
Date
Mood
Sleep hours
Water glasses

Then appends the formatted entry to logs.txt.

**View Logs by Date**

Reads all logs, filters by date, and prints matching records.

**Add Journal Entry**

Takes date
Accepts multi-line text until user enters END
Saves entry with date header and separator line

**Weekly Summary**

Iterates through 7 consecutive dates
Collects and averages mood and sleep
Sums water consumption

## Sample Interaction


------- UpLift: Daily Wellness Tracker -------

        Welcome to Uplift!
Your space to reflect, track, and grow.

1. Add Daily Log
2. Add Journal Entry
3. View Logs by Date
4. View Journal by Date
5. Weekly Summary
6. Exit

Please choose the function you would like to perform: 1
Date (DD/MM/YYYY): 24/11/2025
Mood (1-5): 4
Sleep Hours: 7.5
Water (glasses): 6
Daily log added successfully.

## Testing & Verification Summary


All features were tested individually.
Errors such as pointer mis-handling and incorrect parameter order were resolved.
The program runs smoothly and produces correct outputs for all modules.

## License

This project is developed as part of the UPES First-Year C Programming Course.
You may use or modify it for learning purposes.