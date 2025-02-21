#include <stdio.h>

int main(void)
{
    int k;
    scanf("%d", &k);

    long long n = 1;
    double s = 0;
    while (k >= s)
    {
        s += 1.0 / n;
        n++;
    }

    printf("%lld", n - 1);
}