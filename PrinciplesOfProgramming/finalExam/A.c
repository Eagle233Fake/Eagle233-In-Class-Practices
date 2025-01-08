#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < (n + 1) / 2; i++)
    {
        for (int j = 0; j < i; j++)
        {

            printf(" ");
        }
        for (int j = 0; j < n - 2 * i; j++)
        {
            printf("*");
        }
        for (int j = 0; j < i; j++)
        {

            printf(" ");
        }
        printf("\n");

    }

    for (int i = (n - 1) / 2; i > 0; i--)
    {

        for (int j = 0; j < i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < n - 2 * (i - 1); j++)
        {
            printf("*");

        }
        for (int j = 0; j < i - 1; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}