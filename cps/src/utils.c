#include "utils.h"

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

const char* ERROR_MESSAGE = "Error";

void die()
{
    perror(ERROR_MESSAGE);
    exit(EXIT_FAILURE);
}

void copyMatrix(bool** src, bool** dst, int n)
{
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        dst[j][i] = src[j][i];
}

bool **createMatrix(int n) {
    bool **matrix = (bool **)malloc(n * sizeof(bool *));
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        matrix[i] = (bool *)malloc(n * sizeof(bool));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }

    return matrix;
}

void freeMatrix(bool **matrix, int n) 
{
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(bool** m, int w, int h)
{
    for(int j = 0; j < h; j++)
    {
        for(int i = 0; i < w; i++)
        {
            printf("%d ", ((bool**)m)[j][i]);
        }
        printf("\n");
    }

    return;
}



