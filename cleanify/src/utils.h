#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

bool** createMatrix(int n);
void freeMatrix(bool** matrix, int n);

void printMatrix(bool** m, int w, int h);

#endif

