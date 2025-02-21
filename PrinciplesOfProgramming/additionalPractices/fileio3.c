#include <stdio.h>

int main(void)
{
    FILE *p1 = fopen("i1.txt", "r");

    if (p1 == NULL)
    {
        return 1;
    }

    FILE *p2 = fopen("o1.txt", "a");

    if (p2 == NULL)
    {
        return 1;
    }

    int a, b;
    char c;
    while (fscanf(p1, "%d%c%d", &a, &c, &b) == 3)
    {
        if (c == '+')
        {
            fprintf(p2, "%d\n", a + b);
        }
        else
        {
            fprintf(p2, "%d\n", a - b);
        }
    }

    fclose(p1);

    fclose(p2);
}