#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    getchar();

    char str[n][105];

    int length = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (fgets(str[i], sizeof(str[i]), stdin) != NULL) 
        {
            str[i][strcspn(str[i], "\n")] = '\0';
        }
    }

    for (int i = 0; i < n; i++)
    {
        length = strlen(str[i]);
        for (int j = 0; j < length; j++)
        {
            if (str[i][j] == ' ')
            {
                sum++;
            }
        }
    }
    printf("%d\n", sum);

    for (int i = 0; i < n; i++)
    {
        length = strlen(str[i]);
        for (int j = 0; j < length; j++)
        {
            if (str[i][j] != ' ')
            {
                printf("%c", str[i][j]);
            }
        }
        printf("\n");
    }
}