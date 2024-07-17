#include <stdio.h>

#include "parser.h"
#include "utils.h"

int main()
{

    char filename[] = "demo.cpm";
    int n = getNumberOfTasks(filename);

    if (n > 0)
        printf("Found %d tasks!", n);

    bool** matrix = createMatrix(n);
    parse(filename, matrix, n);

    return 0;
}




