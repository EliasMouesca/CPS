#include <stdio.h>

#include <stdbool.h>
#include <stdlib.h>
#include "cleanify.h"
#include "utils.h"

int main()
{
	int size = 5;
    
    bool matrix[5][5] = {
    	{0, 0, 0, 0, 0},
    	{1, 0, 0, 0, 0},
    	{1, 1, 0, 0, 0},
    	{0, 0, 1, 0, 0},
    	{1, 0, 0, 1, 0},
    };

    /*
    bool matrix[5][5] = {
    	{0, 0, 1, 0, 0},
    	{0, 0, 0, 1, 0},
    	{0, 1, 0, 0, 0},
    	{1, 0, 0, 0, 0},
    	{1, 0, 0, 1, 0},
    };
    */


	bool** input = createMatrix(size);
	bool** output = createMatrix(size);

    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 5; i++)
            input[j][i] = matrix[j][i];
    }

	cleanify(input, output, size);

    freeMatrix(input, size);
    freeMatrix(output, size);

    return 0;
}


