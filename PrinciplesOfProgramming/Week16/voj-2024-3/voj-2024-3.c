#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[1001];
    scanf("%s", s);

    int length = strlen(s);
    int count = 1;
    char n[1001];
    n[0] = s[0];
    int p = 1;
    for (int i = 1; i < length; i++)
    {
        if (s[i] == s[i - 1])
        {
            count++;
        }
        else if (count != 1)
        {
            p += sprintf(n + p, "%d", count);
            p += sprintf(n + p, "%c", s[i]);
            count = 1;
        }
        else
        {
            p += sprintf(n + p, "%c", s[i]);
        }
    }
    if (count != 1)
    {
        p += sprintf(n + p, "%d", count);
    }
    
    n[p] = '\0';
    printf("%s\n", n);
}