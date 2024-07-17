#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdbool.h>
#include <stdlib.h>

// Constants
extern const int MAX_LINE_LENGTH;
extern const int MAX_TASK_NAME_LENGTH;
extern const int MAX_DEPENDENCIES_LENGTH;

// Not constant
extern bool** taskMatrix;
extern char** taskNames;
extern int nTasks;

#endif

