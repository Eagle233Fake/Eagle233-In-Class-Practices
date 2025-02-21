#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b);

int main(void)
{
    char nation[10][100];

    for (int i = 0; i < 10; i++)
    {
        scanf("%s", nation[i]);
    }

    qsort(nation, 10, 100, compare);

    for (int i = 0; i < 10; i++)
    {
        printf("%s\n", nation[i]);
    }
    return 0;
}

int compare(const void *a, const void *b) 
{
    return strcmp((char *)a, (char *)b);
}