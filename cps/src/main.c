#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "cleanify.h"
#include "parser.h"
#include "utils.h"
#include "globals.h"

int main()
{
    char filename[] = "easy.cpm";
    nTasks = getNumberOfTasks(filename);

    if (nTasks <= 0) 
    {
        puts("No tasks were found!");
        exit(EXIT_FAILURE);
    }

    taskNames = malloc(nTasks * sizeof(char*));

    taskMatrix = createMatrix(nTasks);
    bool** tmp = createMatrix(nTasks);
    copyMatrix(taskMatrix, tmp, nTasks);
    
    parse(filename);
    cleanify(tmp, taskMatrix, nTasks);
    freeMatrix(tmp, nTasks);



    freeMatrix(taskMatrix, nTasks);

    return 0;
}




