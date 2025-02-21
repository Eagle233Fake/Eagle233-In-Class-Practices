#include <stdio.h>

int main(void)
{
    long long a, b;

    long long result = 1;
    scanf("%lld %lld", &a, &b);

    for (int i = 0; i < b; i++)
    {
        result = (a * result) % 1000;
    }

    printf("%03lld", result);
}