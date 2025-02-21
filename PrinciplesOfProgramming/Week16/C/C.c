#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char s1[101];
    char s2[101];

    fgets(s1, sizeof(s1), stdin);
    fgets(s2, sizeof(s2), stdin);

    s1[strcspn(s1, "\n")] = '\0';
    s2[strcspn(s2, "\n")] = '\0';

    int l1 = strlen(s1), l2 = strlen(s2);

    char s3[101], s4[101];

    int p1 = 0;
    for (int i = 0; i < l1; i++)
    {
        if (s1[i] != ' ')
        {
            p1 += sprintf(s3 + p1, "%c", tolower(s1[i]));
        }
    }
    s3[p1 + 1] = '\0';

    int p2 = 0;
    for (int i = 0; i < l2; i++)
    {
        if (s2[i] != ' ')
        {
            p2 += sprintf(s4 + p2, "%c", tolower(s2[i]));
        }
    }
    s4[p2 + 1] = '\0';

    if (strcmp(s3, s4) == 0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}