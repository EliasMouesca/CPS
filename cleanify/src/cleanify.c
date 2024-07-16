#include "cleanify.h"

#include "utils.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static bool independentTaskPresent(bool** m, int s);
static bool isTaskIndependent(bool**, int size, int task);
static void clean(bool** matrix, int size);

bool cleanify(bool** input, bool** output, int s)
{
    if (check(input, s) == false) 
    {
        puts("Circular dependency detected!");
        return false;
    }

    clean(output, s);

    printMatrix(input, s, s);
    printf("\n\n");
    printMatrix(output, s, s);

    return true;
}

void cleanTask(bool** matrix, int size, int row)
{
    for (int d = 0; d < size; d++)
    {
        for (int i = 0; i < size; i++)
            if (matrix[row][d] != 0 && matrix[row][i] && matrix[d][i] != 0)
                matrix[row][i] = 0;
        cleanTask(matrix, size, d);
    }

    return;
}

void clean(bool** matrix, int size)
{
    for (int r = 0; r < size; r++)
        cleanTask(matrix, size, r);
}


// Check circular dependency
bool check(bool** m, int size)
{
    for (int s = 1; s < size; s++)
    {
        bool** tmp = createMatrix(s);

        // k is the iterator for the submatrices
        for (int k = 0; k < size - s + 1; k++)
        {
            for (int j = 0; j < s; j++)
            for (int i = 0; i < s; i++)
                tmp[j][i] = m[j + k][i + k];

            if (!independentTaskPresent(tmp, s)) 
                return false;
        }

        freeMatrix(tmp, s);
    }

    return independentTaskPresent(m, size);
}

bool independentTaskPresent(bool** matrix, int size)
{
    for (int i = 0; i < size; i++)
        if (isTaskIndependent(matrix, size, i)) return true;

    return false;
}

bool isTaskIndependent(bool** matrix, int size, int task)
{
    for (int i = 0; i < size; i++)
        if (matrix[task][i] != 0) return false;

    return true;
}






