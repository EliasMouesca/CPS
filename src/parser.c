#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "globals.h"

#include "utils.h"
#include "entry.h"

static bool isTask(char* str);
static void loadStructures(char* filename);
static char format[64];
static const char delimiter = '|';
static const char dependencyDelimiter = ',';
static void fillDependencies(int task);
static bool isTerminator(char c);

int getNumberOfTasks(char* filename)
{
    assert(filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) die("Could not open file '%s':", filename);
    
    int i = 0;
    char* line = malloc(MAX_LINE_LENGTH + 1);
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) 
        if (isTask(line)) i++;

    fclose(file);

    return i;
}

void loadStructures(char* filename)
{
    assert(filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) die("Could not open file '%s':", filename);

    char* line = malloc(MAX_LINE_LENGTH + 1);

    char name[MAX_TASK_NAME_LENGTH + 1];
    int time;
    char depen[MAX_DEPENDENCIES_LENGTH + 1];

    int taskNumber = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        if (!isTask(line)) continue;

        if (sscanf(line, format, name, &time, depen) != NUMBER_OF_FIELDS)
            die("Task %d is not well formed!", taskNumber + 1);

        strip(name);
        strip(depen);
            
        entry* entry = entries + taskNumber;

        entry->name = malloc(MAX_TASK_NAME_LENGTH + 1);
        memcpy(entry->name, name, MAX_TASK_NAME_LENGTH); 
        entry->name[MAX_TASK_NAME_LENGTH] = '\0';

        entry->time = time;

        entry->depen = malloc(MAX_DEPENDENCIES_LENGTH + 1);
        memcpy(entry->depen, depen, MAX_DEPENDENCIES_LENGTH);
        entry->depen[MAX_DEPENDENCIES_LENGTH] = '\0';

        taskNumber++;
    }

    fclose(file);

}

void fillDependencies(int task)
{
    assert(task >= 0);

    const char* dependencies = entries[task].depen;
    char* buffer = malloc(MAX_TASK_NAME_LENGTH + 1);
    int charactersRead = 0;
    int i = 0;
    while (charactersRead < MAX_DEPENDENCIES_LENGTH)
    {
        char c = dependencies[charactersRead];
        if (isTerminator(c))
        {
            buffer[i] = '\0';

            strip(buffer);

            int index = getTaskIndex(buffer, entries, nTasks);
            assert(index >= -1);

            if (index == -1) die("'%s' is not a recognized dependency (task %d)", buffer, task + 1);

            taskMatrix[task][index] = 1;
        }
        else buffer[i] = c;

        i++;
        charactersRead++;

        if (isTerminator(c))
        {
            if (c == dependencyDelimiter)
                i = 0;
            else break;
        }
    }

    return;

}

bool isTerminator(char c) { 
    return (c == '\n' || c == '\0' || c == dependencyDelimiter); 
}

bool parse(char* filename)
{
    assert(filename);

    snprintf(format, sizeof(format), 
            " %%%d[^%c] %c %%d %c %%%d[^\n]", 
            MAX_TASK_NAME_LENGTH, 
            delimiter, delimiter, delimiter, 
            MAX_TASK_NAME_LENGTH);
    
    loadStructures(filename);

    for (int i = 0; i < nTasks; i++)
    {
        if (strcmp(entries[i].depen, "-") == 0) continue;
        fillDependencies(i);
    }

    return true;
}


bool isTask(char* str)
{
    if (str == NULL) return false;
    if (str[0] == '#' || str[0] == '\n') return false;

    return true;
}


