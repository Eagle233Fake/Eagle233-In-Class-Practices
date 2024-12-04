#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b);
int casecompare(const void *a, const void *b); 


int main(void)
{
    char way[10];
    scanf("%s", way);

    int n;
    scanf("%d", &n);

    char str[n][1005];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str[i]);
    }

    if (strcmp(way, "inc") == 0)
    {
        qsort(str, n, sizeof(str[0]), compare);
        for (int i = 0; i < n; i++)
        {
            printf("%s\n", str[i]);
        }
    }

    else if (strcmp(way, "dec") == 0)
    {
        qsort(str, n, sizeof(str[0]), compare);
        for (int i = n - 1; i >= 0; i--)
        {
            printf("%s\n", str[i]);
        }
    }

    if (strcmp(way, "ncinc") == 0)
    {
        qsort(str, n, sizeof(str[0]), casecompare);
        for (int i = 0; i < n; i++)
        {
            printf("%s\n", str[i]);
        }
    }

    if (strcmp(way, "ncdec") == 0)
    {
        qsort(str, n, sizeof(str[0]), casecompare);
        for (int i = n - 1; i >= 0; i--)
        {
            printf("%s\n", str[i]);
        }
    }
}

int compare(const void *a, const void *b) 
{
    return strcmp((char *)a, (char *)b);
}

int casecompare(const void *a, const void *b) 
{
    return strcasecmp((char *)a, (char *)b);
}