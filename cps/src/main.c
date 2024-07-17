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

    if (nTasks > 0) printf("Found %d tasks!", nTasks);
    else return -1;

    taskNames = malloc(nTasks * sizeof(char*));

    taskMatrix = createMatrix(nTasks);
    bool** tmp = createMatrix(nTasks);
    copyMatrix(taskMatrix, tmp, nTasks);
    
    parse(filename);
    cleanify(tmp, taskMatrix, nTasks);

    return 0;
}




