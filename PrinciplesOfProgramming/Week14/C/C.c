#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b);

int main(void)
{
    int n;
    scanf("%d", &n);

    char str[n][20];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str[i]);
    } 

    qsort(str, n, sizeof(str[0]), cmp);

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", str[i]);
    }
}

int cmp(const void *a, const void *b)
{
    char birth1[9];
    char birth2[9];

    strncpy(birth1, (const char *)a + 6, 8);
    strncpy(birth2, (const char *)b + 6, 8);
    birth1[8] = '\0';
    birth2[8] = '\0';

    if (strcmp(birth1, birth2) != 0)
    {
        return strcmp(birth2, birth1);
    }
    else
    {
        return strcmp((const char *)b, (const char *)a);
    }
}