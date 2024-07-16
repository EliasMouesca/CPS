#ifndef ENTRY_H
#define ENTRY_H

const int ENTRY_NAME_SIZE = 64;

typedef struct entry
{
    char n[ENTRY_NAME_SIZE];
    int t;
    entry* d;
} entry;

#endif

