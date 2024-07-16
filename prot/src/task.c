#include "task.h"

#include <stdio.h>

void printTask(task* t)
{
    printf("Name: %s\n", t->n);
    printf("Time: %i\n", t->t);
    if (t->d)
        printf("Dependency: %s\n", t->d->n);
    
    return;
}

