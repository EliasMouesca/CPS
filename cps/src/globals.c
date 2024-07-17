#include "globals.h"

const size_t MAX_LINE_LENGTH = 128;
const size_t MAX_TASK_NAME_LENGTH = 32;
const size_t MAX_DEPENDENCIES_LENGTH = 96;
const int NUMBER_OF_FIELDS = 3;

bool** taskMatrix = NULL;
char** taskNames = NULL;
int nTasks = 0;


