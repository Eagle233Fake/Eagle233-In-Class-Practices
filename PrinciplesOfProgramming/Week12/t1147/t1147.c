#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int scores[n];

    char *names[n][1000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &scores[i]);
        scanf("%s", &names[i]);
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (scores[i] > max)
        {
            max = scores[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (scores[i] == max)
        {
            printf("%s\n", names[i]);
            return 0;
        }
    }

}