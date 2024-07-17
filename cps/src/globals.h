#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdbool.h>
#include <stdlib.h>

// Constants
extern const size_t MAX_LINE_LENGTH;
extern const size_t MAX_TASK_NAME_LENGTH;
extern const size_t MAX_DEPENDENCIES_LENGTH;
extern const int NUMBER_OF_FIELDS;

// Not constant
extern bool** taskMatrix;
extern char** taskNames;
extern int nTasks;

#endif

