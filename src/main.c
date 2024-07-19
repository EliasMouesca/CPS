#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "cleanify.h"
#include "parser.h"
#include "utils.h"
#include "globals.h"

int main()
{
    char filename[] = "demos/easy.cpm";
    if (filename == NULL) die("Error opening tasks file.");
    else nTasks = getNumberOfTasks(filename);

    if (nTasks <= 0) die("No tasks found!");

    entries = calloc(nTasks, sizeof(entry));

    taskMatrix = createMatrix(nTasks);
    bool** tmp = createMatrix(nTasks);
    copyMatrix(taskMatrix, tmp, nTasks);
    
    parse(filename);
    cleanify(taskMatrix, tmp, nTasks);

    copyMatrix(tmp, taskMatrix, nTasks);
    freeMatrix(tmp, nTasks);


    printMatrix(taskMatrix, nTasks, nTasks);



    freeMatrix(taskMatrix, nTasks);

    return 0;
}




