#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "globals.h"

#include "utils.h"

static bool isTask(char* str);

int getNumberOfTasks(char* filename)
{
    if (filename == NULL) die();

    FILE* file = fopen(filename, "r");
    if (file == NULL) die();
    
    int i = 0;
    char* line = malloc(MAX_LINE_LENGTH);
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) 
        if (isTask(line)) i++;

    fclose(file);

    return i;
}

bool parse(char* filename)
{
    if (filename == NULL) die();

    FILE* file = fopen(filename, "r");
    if (file == NULL) die();

    char name[MAX_TASK_NAME_LENGTH];
    int time;
    char depen[MAX_DEPENDENCIES_LENGTH];

    const char delimiter = '|';
    char format[64];
    snprintf(format, sizeof(format), 
            "%%%ld[^%c] %c %%d %c %%%ld[^\n]", 
            sizeof(name) - 1, delimiter, delimiter, delimiter, sizeof(depen) - 1);

    char* line = malloc(MAX_LINE_LENGTH);
    int lineNumber = 1;
    int taskNumber = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        if (!isTask(line)) continue;

        int read = sscanf(line, format, name, &time, depen);
        if (read != 3) printf("Error encountered on line '%d' of file '%s'\n", lineNumber, filename);
        else
        {
            printf("\nName:'%s'\nTime: %d\nDependencies: '%s'\n\n", name, time, depen);
            printMatrix(taskMatrix, nTasks, nTasks);

            //name = strip(name);
            
            taskNames[taskNumber] = malloc(sizeof(name));
            memcpy(taskNames[taskNumber], name, sizeof(name)); 



            taskNumber++;

        }

        lineNumber++;
    }



    fclose(file);

    return true;
}


bool isTask(char* str)
{
    if (str == NULL) return false;
    if (str[0] == '#' || str[0] == '\n') return false;

    return true;
}


