#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char name[31];
    char sex;
    int length;
}student;

int compare(const void *a, const void *b);

int main(void)
{
    int n;
    scanf("%d", &n);

    student students[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %c %d", students[i].name, &students[i].sex, &students[i].length);
    }

    qsort(students, n, sizeof(student), compare);

    for (int i = 0; i < n; i++)
    {
        printf("%s %c %d\n", students[i].name, students[i].sex, students[i].length);
    }
}

int compare(const void *a, const void *b)
{
    student one = *(const student *)a;
    student two = *(const student *)b;

    if (one.sex == two.sex)
    {
        if (one.length == two.length)
        {
            return strcmp(one.name, two.name);
        }
        return one.length - two.length;
    }
    return two.sex - one.sex;
}