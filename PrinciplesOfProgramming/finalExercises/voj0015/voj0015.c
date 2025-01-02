#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *f = fopen("info.txt", "r");
    if (f == NULL)
    {
        return 0;
    }

    FILE *f2 = fopen("info2.txt", "a");
    if (f2 == NULL)
    {
        return 0;
    }

    char s[1000001];
    while (fgets(s, 1000001, f))
    {
        int d;
        char c;
        double lf;
        int check = sscanf(s, "%d %c %lf", &d, &c, &lf);
        if (check != 3)
        {
            continue;
        }

        double result;
        if (c == '+')
        {
            result = d + lf;
        }
        else if (c == '-')
        {
            result = d - lf;
        }
        else if (c == '*')
        {
            result = d * lf;
        }
        else if (c == '/')
        {
            if (lf == 0)
            {
                continue;
            }
            result = d / lf;
        }
        else
        {
            continue;
        }
        fprintf(f2, "%.2lf\n", result);
    }

    fclose(f);
    fclose(f2);
}