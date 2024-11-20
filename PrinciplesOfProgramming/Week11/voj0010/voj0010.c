#include <stdio.h>

int func1(int m);

int main(void)
{
    int n;
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n - 1; i++)
    {
        func1(m);
    }

    printf("%d\n", func1(m));
}

int func1(int m)
{
    static int var1 = 1;
    var1 += m;
    return var1;
}