#include "taskList.h"
#include <stdbool.h>

const static size_t INITIAL_VIRTUAL_SIZE = 4;

bool createTaskList(taskList* l)
{
    if (l == NULL) return false;
    
    task->begin = calloc(INITIAL_VIRTUAL_SIZE, sizeof(task));
    if (task->begin == NULL) return false;
    task->virtualSize = INITIAL_VIRTUAL_SIZE;
    task->size = 0;

    return true;
}

bool addTask(taskList* l, task t)
{
    if (l == NULL) return false;
    

    return true;
}





