#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

#include "entry.h"

// General
void die(const char* fmt, ...);
int getTaskIndex(char* name, entry* entries, int nEntries);

// Matrix
bool** createMatrix(int n);
void freeMatrix(bool** matrix, int n);
void copyMatrix(bool** src, bool** dst, int n);
void printMatrix(bool** m, int w, int h);

// Strings
void strip(char* str);


#endif

