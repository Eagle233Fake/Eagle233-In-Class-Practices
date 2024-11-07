#include <stdio.h>

int function(int n);

int main(void)
{
    int n;
    scanf("%d", &n);

    printf("%d\n", function(n));
}

int function(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }

    if (n >= 2)
    {
        return (n * function(n - 1));
    }
}