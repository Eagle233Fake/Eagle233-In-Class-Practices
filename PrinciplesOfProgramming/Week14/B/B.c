#include <stdio.h>

int isEnough(int n);

int remain(int n, int high);

int main(void)
{
    int n;
    char c;
    scanf("%d %c", &n, &c);
    int high = isEnough(n);
    int remained = remain(n, high);

    for (int i = high; i > 0; i -= 2)
    {
        for (int j = 0; j < (high - i) / 2; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("%c", c);
        }
        for (int j = 0; j < (high - i) / 2; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
    for (int i = 3; i <= high; i += 2)
    {
        for (int j = 0; j < (high - i) / 2; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("%c", c);
        }
        for (int j = 0; j < (high - i) / 2; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
    printf("%d", remained);
}

int isEnough(int n)
{
    for (int i = 1; i < n; i += 2)
    {
        int m = n;
        for (int j = i; j > 0; j -= 2)
        {
            m -= j * 2;
        }
        m += 1;
        if (m < 0)
        {
            return i - 2;
        }
    }
}

int remain(int n, int high)
{
    for (int i = high; i > 0; i -= 2)
    {
        n -= i * 2;
    }
    return n + 1;
}
