#include <stdio.h>

typedef union scores
{
    double score;
    char rank;
}scores;

typedef struct student
{
    int id;
    char name[51];
    int score_type;
    scores score;
}student;

int main(void)
{
    student students;
    while (scanf("%d %s %d", &students.id, students.name, &students.score_type) == 3)
    {
        getchar();
        if (students.score_type == 0)
        {
            scanf("%lf", &students.score.score);
            printf("ID: %d, Name: %s, Score Type: %d, Score: %.1lf\n", students.id, students.name, students.score_type, students.score.score);
        }
        else
        {
            scanf("%c", &students.score.rank);
            printf("ID: %d, Name: %s, Score Type: %d, Grade: %c\n", students.id, students.name, students.score_type, students.score.rank);
        }
    }
}