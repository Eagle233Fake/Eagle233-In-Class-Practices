#include <stdio.h>

int jump(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else
    {
        return jump(n - 1) + jump (n - 2);
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", jump(n));
}