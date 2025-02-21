#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char name[21];
    int y;
    int m;
    int d;
}student;

int cmp(const void *a, const void *b);

int main(void)
{
    int n;
    scanf("%d", &n);

    student students[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", students[i].name, &students[i].y, &students[i].m, &students[i].d);
    }

    qsort(students, n, sizeof(student), cmp);

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", students[i].name);
    }
}

int cmp(const void *a, const void *b)
{
    student m = *((student *)a);
    student n = *((student *)b);
    if (m.y == n.y)
    {
        if (m.m == n.m)
        {
            if (m.d == n.d)
            {
                return 1;
            }
            return m.d - n.d;
        }
        return m.m - n.m;
    }
    return m.y - n.y;
}