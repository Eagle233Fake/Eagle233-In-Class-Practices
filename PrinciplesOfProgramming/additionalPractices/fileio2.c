#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    FILE *f1 = fopen("input.txt", "r");
    if (f1 == NULL)
    {
        return 1;
    }
    FILE *f2 = fopen("output.txt", "a");
    if (f2 == NULL)
    {
        return 1;
    }

    char s[1000];
    while (fgets(s, 1000, f1))
    {
        int l = strlen(s);
        for (int i = 0; i < l; i++)
        {
            s[i] = tolower(s[i]);
        }

        fputs(s, f2);
    }

    fclose(f1);
    fclose(f2);
}