#ifndef TASK_H
#define TASK_H

#define NAME_MAX_LEN 64

typedef struct task
{
    char n[NAME_MAX_LEN];
    int t;
    struct task* d;
} task;

void printTask(task*);

#endif

