#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n);

int main(void)
{
    int x, y;

    scanf("%d %d",&x, &y);

    int m = 0;

    for (int i = x; i <= y; i++)
    {
        if (isPrime(i) && i != 1)
        {
            m++;
        }
    }

    printf("%d\n", m);
}

bool isPrime(int n)
{
    for (int j = 2; j * j <= n; j++)
    {
        if (n % j == 0)
        {
            return false;
        }
    }
    return true;
}