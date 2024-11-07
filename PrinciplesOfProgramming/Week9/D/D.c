#include <stdio.h>

long long gcd(long long a, long long b);

int main(void)
{
    long long n, m;
    scanf("%lld %lld", &n, &m);

    printf("%lld", gcd(n, m));
}

long long gcd(long long a, long long b)
{
    long long temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }    
    return temp;
}