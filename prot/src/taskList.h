#ifndef TASK_LIST_H
#define TASK_LIST_H

#include "task.h"
#include <stdbool.h>

typedef struct
{
    task* begin;
    size_t size;

    size_t virtualSize;        // "Private", should not be used!
} taskList;

bool createTaskList(taskList* l);
bool addTask(taskList* l, task t);
bool destroyTaskList(taskList* l);

#endif

