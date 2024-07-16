#include <stdio.h>
int main()
{

    char name[32];
    int time;
    char depen[128];

    const char delimiter = '|';

    char formatString[160];

    snprintf(formatString, sizeof(formatString), "%%[^%c] %c %%d %c %%[^\n]", delimiter, delimiter, delimiter);

    //printf("%s", formatString);

    scanf(formatString, name, &time, depen);

    printf("Name: %s\nTime: %d\nDependencies: %s\n", name, time, depen);

    return 0;
}

