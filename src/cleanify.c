#include "cleanify.h"

#include "utils.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static bool check(bool** m, int size);
static void clean(bool** matrix, int size);
static void cleanDependency(bool** matrix, int size, int row, int drow);

static bool independentTaskPresent(bool** m, int s);
static bool isTaskIndependent(bool**, int size, int task);

// Cleanify takes a matrix of task as input and
// dies if circular dependency is detected
// or loads output with the redundancy-free version of the input.
void cleanify(bool** input, bool** output, int s)
{
    if (check(input, s) == false) die("Circular dependency detected!");

    copyMatrix(input, output, s);

    clean(output, s);

    return;
}

void cleanDependency(bool** matrix, int size, int task, int depen)
{
    // If the task depends on an independent task, you can't reduce it
    if (isTaskIndependent(matrix, size, depen)) return;

    // For each posible dependency (i)
    for (int i = 0; i < size; i++)
        // If the task (task) depends on the (i) task
        if (matrix[depen][i] != 0)
        {
            // Then, if the dependency (depen) itself has 
            // also the same dependency (i) as the task (task)...
            if (matrix[task][i] != 0 && matrix[depen][i] != 0)
                // Well, the task shouldn't have that dependency (i)
                matrix[task][i] = 0;

            // Also, check for the subdependencies !
            cleanDependency(matrix, size, task, i);
        }

    return;
}

// Cleans the matrix of redundancies, must be checked for
// circular dependencies before !!
void clean(bool** matrix, int size)
{
    // For each task...
    for (int r = 0; r < size; r++)
        // For each dependency...
        for (int d = 0; d < size; d++)
            // If this cell is actually saying something...
            // (r has a dependency on d)
            if (matrix[r][d] != 0)
                // Then try to clean this dependency
                cleanDependency(matrix, size, r, d);

    return;
}


// Check circular dependency
bool check(bool** matrix, int size)
{
    // For each possible size of the submatrix of 'matrix'
    for (int s = 1; s <= size; s++)
    {
        // Create the submatrix
        bool** sm = createMatrix(s);

        // k is the iterator for the submatrices
        for (int k = 0; k < size - s + 1; k++)
        {
            // Load the submatrix with values from 'matrix'
            for (int j = 0; j < s; j++)
            for (int i = 0; i < s; i++)
                sm[j][i] = matrix[j + k][i + k];

            // Check if there's at least one independent task
            if (!independentTaskPresent(sm, s)) 
            {
                // If not => circular dependency !
                freeMatrix(sm, s);
                return false;
            }
        }
        freeMatrix(sm, s);
    }

    return true;
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






