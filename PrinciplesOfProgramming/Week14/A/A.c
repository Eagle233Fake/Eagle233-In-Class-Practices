// VOJ不会过。。。

#include <stdio.h>
#include <stdbool.h>

bool Prime[1000000001];

void isPrime(int n);
bool isSuperPrime(int n);

int main(void)
{
    int n;
    scanf("%d", &n);

    isPrime(n);

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (Prime[i] && isSuperPrime(i))
        {
            sum++;
        }
    }

    printf("%d\n", sum);
}

void isPrime(int n)
{
    for (int i = 0; i <= n; i++)
    {
        Prime[i] = true;
    }
    Prime[0] = Prime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (Prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                Prime[j] = false;
            }
        }
    }
}

bool isSuperPrime(int n)
{
    while (n > 0)
    {
        if (!Prime[n]) 
        {
            return false;
        }
        n = n / 10; 
    }
    return true;
}