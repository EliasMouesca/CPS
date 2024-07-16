#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#include "task.h"

void handleArgs(int argc, char** argv);

int main(int argc, char** argv)
{
   
   

    return 0;

}

void handleArgs(int argc, char** argv)
{
    int opt;

	static struct option long_options[] = {
        {"format",  required_argument, 0, 'f'},
        {"input",   required_argument, 0, 'i'},
        {"output",  required_argument, 0, 'o'},
        {0, 0, 0, 0}
    };

    while ( (opt = getopt_long(argc, argv, "f:i:o:", long_options, NULL)) != -1)
    {
        switch (opt)
        {
            case 'f':
                printf("f: %s\n", optarg);
                break;

            case 'i':
                printf("i: %s\n", optarg);
                break;

            case 'o':
                printf("o: %s\n", optarg);
                break;
        }
    }
}

