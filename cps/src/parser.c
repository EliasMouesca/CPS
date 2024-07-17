#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "globals.h"

#include "utils.h"
#include "entry.h"

static bool isTask(char* str);
static void loadStructures(char* filename);
static char format[64];
static const char delimiter = '|';
static entry* entries;

int getNumberOfTasks(char* filename)
{
    if (filename == NULL) die();

    FILE* file = fopen(filename, "r");
    if (file == NULL) die();
    
    int i = 0;
    char* line = malloc(MAX_LINE_LENGTH + 1);
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) 
        if (isTask(line)) i++;

    fclose(file);

    return i;
}

void loadStructures(char* filename)
{
    if (filename == NULL) die();

    FILE* file = fopen(filename, "r");
    if (file == NULL) die();

    char* line = malloc(MAX_LINE_LENGTH + 1);

    char name[MAX_TASK_NAME_LENGTH + 1];
    int time;
    char depen[MAX_DEPENDENCIES_LENGTH + 1];

    int taskNumber = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        if (!isTask(line)) continue;

        if (sscanf(line, format, name, &time, depen) != NUMBER_OF_FIELDS)
        {
            printf("Task %d is not well formed! Exiting...\n", taskNumber + 1);
            exit(EXIT_FAILURE);
        }

        strip(name);
            
        entry* entry = entries + taskNumber;

        entry->name = malloc(MAX_TASK_NAME_LENGTH + 1);
        memcpy(entry->name, name, MAX_TASK_NAME_LENGTH); 
        entry->time = time;
        entry->depen = malloc(MAX_DEPENDENCIES_LENGTH + 1);
        memcpy(entry->depen, depen, MAX_DEPENDENCIES_LENGTH);

        taskNumber++;
    }

    fclose(file);

}

bool parse(char* filename)
{
    snprintf(format, sizeof(format), 
            " %%%ld[^%c] %c %%d %c %%%ld[^\n]", 
            MAX_TASK_NAME_LENGTH, 
            delimiter, delimiter, delimiter, 
            MAX_TASK_NAME_LENGTH);
    
    entries = calloc(nTasks, sizeof(entry));

    loadStructures(filename);

    for (int i = 0; i < nTasks; i++)
    {
        printf("%d -> '%s'\n", i, entries[i].name);
    }

    return true;
}


bool isTask(char* str)
{
    if (str == NULL) return false;
    if (str[0] == '#' || str[0] == '\n') return false;

    return true;
}


