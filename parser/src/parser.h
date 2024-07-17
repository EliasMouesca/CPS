#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>

int getNumberOfTasks(char*);
bool parse(char* filename, bool** matrix, int size);

#endif

