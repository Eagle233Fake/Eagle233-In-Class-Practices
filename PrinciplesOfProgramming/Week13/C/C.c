#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct charstr
{
    int index;
    char c;
}
charstr;

int compare(const void *a, const void *b);

int main(void)
{
    char str[1005];
    scanf("%s", str);

    int length = strlen(str);
    charstr sorted[length];
    for (int i = 0; i < length; i++)
    {
        sorted[i].c = str[i];
        sorted[i].index = i;
    }

    qsort(sorted, length, sizeof(charstr), compare);

    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += abs(sorted[i].index - i);
    }
    printf("%d\n", sum);
}

int compare(const void *a, const void *b)
{
    return (((charstr *)a)->c - ((charstr *)b)->c);
}