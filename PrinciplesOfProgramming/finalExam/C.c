#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char name[50];
    int id;
    int score;
}student;

int cmp(const void * a, const void *b);

int main(void)
{
    int n;
    scanf("%d", &n);

    student students[n];
    for (int i = 0; i < n; i++)
    {

        scanf("%s %d %d", students[i].name, &students[i].id, &students[i].score);
    }

    qsort(students, n, sizeof(student), cmp);
    for (int i = 0; i < n; i++)
    {

        printf("%s %d %d\n", students[i].name, students[i].id, students[i].score);
    }
}

int cmp(const void * a, const void *b)
{
    student c = *((student *)a);
    student d = *((student *)b);

    if (c.score == d.score)
    {
        return c.id - d.id;
    }
    return d.score - c.score;
}