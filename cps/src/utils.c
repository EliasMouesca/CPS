#include "utils.h"

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

const char* ERROR_MESSAGE = "Error";

void strip(char* str)
{
    int len = strlen(str);

    int i = 0;
    while ( str[i] != '\0' && isspace(str[i]) ) i++;

    int j = len - 1;
    while ( str[j] != '\0' && isspace(str[j]) ) j--;

    int newLen = j - i + 1;
    char* tmp = malloc( (newLen + 1) * sizeof(char) );

    memcpy(tmp, str + i, newLen);
    memcpy(str, tmp, newLen);
    str[newLen] = '\0';

    return;
}

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



