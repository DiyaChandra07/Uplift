#ifndef JOURNAL_H
#define JOURNAL_H

/*

Append a journal entry to journal.txt int the format 
DD/MM/YYYY
_text_
---- (seperator)

*/

int add_journal_entry(const char *filename, int d, int m, int y, const char *text);

/*

Search journal.txt for specific date header and prints
until the seperator ----

*/

int view_journal_by_date(const char *filename, int d, int m, int y);

#endif