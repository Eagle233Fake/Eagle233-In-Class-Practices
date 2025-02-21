#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b);

typedef struct student
{
    char name[21];
    int score;
}student;

int main(void)
{
    int n;
    scanf("%d", &n);

    student students[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", students[i].name, &students[i].score);
    }

    qsort(students, n, sizeof(student), compare);

    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", students[i].name, students[i].score);
    }
}

int compare(const void *a, const void *b)
{
    student one = *(student *)a;
    student two = *(student *)b;

    if (one.score == two.score)
    {
        return strcmp(one.name, two.name);
    }
    return two.score - one.score;
}