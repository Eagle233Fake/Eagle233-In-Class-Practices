#include <stdio.h>
#include <stdlib.h>

typedef struct date
{
    int y;
    int m;
    int d;
}date;

int cmp(const void *a, const void *b);

int main(void)
{
    int n;
    scanf("%d", &n);

    date dates[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d/%d/%d", &dates[i].m, &dates[i].d, &dates[i].y);
    }

    qsort(dates, n, sizeof(date), cmp);

    for (int i = 0; i < n; i++)
    {
        printf("%02d/%02d/%04d\n", dates[i].m, dates[i].d, dates[i].y);
    }
}

int cmp(const void *a, const void *b)
{
    date m = *((date *)a);
    date n = *((date *)b);
    if (m.y == n.y)
    {
        if (m.m == n.m)
        {
            return m.d - n.d;
        }
        return m.m - n.m;
    }
    return m.y - n.y;
}