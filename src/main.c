#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <getopt.h>
#include <assert.h>
#include <string.h>

#include "cleanify.h"
#include "parser.h"
#include "utils.h"
#include "globals.h"

#define DEFAULT_INPUT "input.cpm"
#define DEFAULT_OUTPUT "output.md"

static void printHelpMessage(char* alias);

int main(int argc, char** argv)
{

    // -- Handle arguments --
    int opt;
    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"input", required_argument, 0, 'i'},
        {"output", required_argument, 0, 'o'},
        {0, 0, 0, 0}
    };

    char* input = NULL;
    char* output = NULL;

    while ((opt = getopt_long(argc, argv, "hi:o:", long_options, NULL)) != -1) {
        switch (opt) {
            case 'h':
                printHelpMessage(*argv);
                exit(EXIT_SUCCESS);
            case 'i':
                input = strdup(optarg);
                break;
            case 'o':
                output = strdup(optarg);
                break;
            case '?':
                exit(EXIT_FAILURE);
                break;
            default:
                exit(EXIT_FAILURE);
        }
    }

    if (input == NULL)
    {
        input = malloc(sizeof(DEFAULT_INPUT));
        strcpy(input, DEFAULT_INPUT);
    }

    if (output == NULL)
    {
        output = malloc(sizeof(DEFAULT_OUTPUT));
        strcpy(output, DEFAULT_OUTPUT);
    }
    
    assert(input);

    // -- Checking input --
    nTasks = getNumberOfTasks(input);

    if (nTasks <= 0) die("No tasks were found in file '%s'!", input);

    entries = calloc(nTasks, sizeof(entry));

    taskMatrix = createMatrix(nTasks);
    bool** tmp = createMatrix(nTasks);
    copyMatrix(taskMatrix, tmp, nTasks);
    
    parse(input);
    cleanify(taskMatrix, tmp, nTasks);

    copyMatrix(tmp, taskMatrix, nTasks);
    freeMatrix(tmp, nTasks);

    // -- Begin actual solving --
    printMatrix(taskMatrix, nTasks, nTasks);



    // -- Finish program, clean --
    free(entries);
    free(input);
    free(output);
    freeMatrix(taskMatrix, nTasks);

    return 0;
}

void printHelpMessage(char* alias)
{
    printf("Usage: %s \n", alias);
    printf("    -h, --help      Display help message\n");
    printf("    -i, --input     Specify input file\n");
    printf("    -o, --output    Specify output file\n");
    return;
}


