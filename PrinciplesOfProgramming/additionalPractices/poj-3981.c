#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[1001];
    gets(s);

    int l = strlen(s);

    for (int i = 0; i < l; i++)
    {
        if (strncmp(&s[i], "you", 3) == 0)
        {
            printf("we");
            i += 2;
        }
        else
        {
            putchar(s[i]);
        }
    }
}