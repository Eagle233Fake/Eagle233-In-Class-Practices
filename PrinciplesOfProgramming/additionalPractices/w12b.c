#include <stdio.h>
#include <string.h>

int main(void)
{
    int k;
    scanf("%d", &k);

    char s[1001];
    scanf("%s", s);

    int l = strlen(s);
    int map[26] = {0};
    for (int i = 0; i < l; i++)
    {
        map[s[i] - 'a']++;
    }

    for (int i = 0; i < l; i++)
    {
        if (map[s[i] - 'a'] == k)
        {
            printf("%c\n", s[i]);
            return 0;
        }
    }
    printf("no\n");
}