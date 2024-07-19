#include "globals.h"
#include "entry.h"

const int MAX_LINE_LENGTH = 128;
const int MAX_TASK_NAME_LENGTH = 32;
const int MAX_DEPENDENCIES_LENGTH = 96;
const int NUMBER_OF_FIELDS = 3;

bool** taskMatrix = NULL;
entry* entries = NULL;
int nTasks = 0;


