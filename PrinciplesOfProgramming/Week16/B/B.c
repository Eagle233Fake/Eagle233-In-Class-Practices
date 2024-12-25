#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n / 2; i++)
    {
        for (int j = 0; j < i - 1; j++)
        {
            printf(" ");
        }
        printf("X");
        for (int j = 0; j < n - i * 2; j++)
        {
            printf(" ");
        }
        printf("X");
        for (int j = 0; j < i - 1; j++)
        {
            printf(" ");
        }
        printf("\n");
    }

    for (int i = 0; i < n / 2; i++)
    {
        printf(" ");
    }
    printf("X");
    for (int i = 0; i < n / 2; i++)
    {
        printf(" ");
    }
    printf("\n");

    for (int i = 2 + n / 2; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        printf("X");
        for (int j = 0; j < 2 * (i - 1 - n / 2) - 1; j++)
        {
            printf(" ");
        }
        printf("X");
        for (int j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}