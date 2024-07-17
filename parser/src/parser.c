#include "parser.h"

#include <stdio.h>
#include <stdlib.h>

const int MAX_LINE_LENGTH = 128;

static bool isTask(char* str);

int getNumberOfTasks(char* filename)
{
    if (filename == NULL) 
    {
        puts("Input file can't be null");
        return -1;
    }

    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("There was an error opening '%s' file.", filename);
        return -1;
    }
    
    int i = 0;
    char* line = malloc(MAX_LINE_LENGTH);
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) 
        if (isTask(line)) i++;

    fclose(file);

    return i;
}

bool parse(char* filename, bool** matrix, int size)
{
    if (filename == NULL) 
    {
        puts("Input file can't be null");
        return false;
    }

    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("There was an error opening '%s' file.", filename);
        return false;
    }


    char name[32];
    int time;
    char depen[96];

    const char delimiter = '|';
    char format[64];
    snprintf(format, sizeof(format), "%%[^%c] %c %%d %c %%[^\n]", delimiter, delimiter, delimiter);

    
    char* line = malloc(MAX_LINE_LENGTH);
    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        if (!isTask(line)) continue;

        int read = sscanf(line, format, name, &time, depen);
        if (read != 3) printf("Error encountered on line '%d' of file '%s'\n", i + 1, filename);
        printf("Name: %s\nTime: %d\nDependencies: %s\n\n", name, time, depen);

        i++;
    }



    fclose(file);
}


bool isTask(char* str)
{
    if (str == NULL) return false;
    if (str[0] == '#' || str[0] == '\n') return false;

    return true;
}


