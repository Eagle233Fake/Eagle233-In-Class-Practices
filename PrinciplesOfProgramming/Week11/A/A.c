#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long cal(long long x);

int main(void)
{
    char str[1000];
    scanf("%s", str);

    char x_s[1000];
    int length = strlen(str);

    for (int i = 0; i < length - 1; i++)
    {
        x_s[i] = str[i];
    }

    long long x = atoi(str);

    printf("%lld", cal(x));
}

long long cal(long long x)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        return x * cal(x - 1);
    }
}