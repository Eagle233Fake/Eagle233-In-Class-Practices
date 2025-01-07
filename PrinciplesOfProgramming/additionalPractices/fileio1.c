#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    FILE *f = fopen("input.txt", "r");
    if (f == NULL)
    {
        return 1;
    }
    FILE *f2 = fopen("output.txt", "a");
    if (f2 == NULL)
    {
        return 1;
    }

    char s[1000];
    while (fgets(s, 1000, f) != NULL)
    {
        int length = strlen(s);
        for (int i = 0; i < length; i++)
        {
            s[i] = toupper(s[i]);
        }
        fputs(s, f2);
    }

    fclose(f);
    fclose(f2);
}