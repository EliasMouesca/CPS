#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdbool.h>
#include <stdlib.h>

#include "entry.h"

// Constants
extern const int MAX_LINE_LENGTH;
extern const int MAX_TASK_NAME_LENGTH;
extern const int MAX_DEPENDENCIES_LENGTH;
extern const int NUMBER_OF_FIELDS;

// Not constant
extern bool** taskMatrix;
extern entry* entries;
extern int nTasks;

#endif

