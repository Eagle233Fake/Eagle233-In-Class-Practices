#include <stdio.h>
#include <string.h>

typedef struct student
{
    char name[21];
    int score;
}student;

int main(void)
{
    student students[1000];

    int index = 0;
    
    // VOJ 平台无法识别 true。。。所以这里直接用1
    while (1)
    {
        char state[8];
        scanf("%s", state);

        if (strcmp(state, "insert") == 0)
        {
            int found = 0;
            char tempName[21];
            int tempScore;
            scanf("%s %d",tempName, &tempScore);
            for (int i = 0; i <= index; i++)
            {
                if (strcmp(tempName, students[i].name) == 0)
                {
                    found = 1;
                    if (tempScore > students[i].score)
                    {
                        students[i].score = tempScore;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (found == 0)
            {
                strcpy(students[index].name, tempName);
                students[index].score = tempScore;
                index++;
            }
        }
        else if (strcmp(state, "find") == 0)
        {
            int found = 0;
            char tempName[21];
            scanf("%s", tempName);
            for (int i = 0; i <= index; i++)
            {
                if (strcmp(tempName, students[i].name) == 0)
                {
                    printf("%d\n", students[i].score);
                    found = 1;
                    break;
                }
            }
            if (found == 0)
            {
                printf("-1\n");
            }
        }
        else if (strcmp(state, "end") == 0)
        {
            return 0;
        }
    }
}