#include <stdio.h>

int main(void)
{

    char s[105];
    scanf("%s", s);

    int length = strlen(s);

    for (int i = 0; i < length; i++)
    {
        if ((s[i] == 'a') || (s[i] == 'e') ||( s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u') ||(s[i] == 'A') || (s[i] == 'E') || (s[i] == 'I') || (s[i] == 'O') || (s[i] == 'U'))
        {
            continue;
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
