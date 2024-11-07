#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPrime(long long int n);
bool isSymm(long long int n);

int main(void)
{
    long long int number[5];

    for (int i = 0; i < 5; i++)
    {
        scanf("%lld", &number[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        if (isPrime(number[i]) && isSymm(number[i]))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}

bool isPrime(long long int n)
{
    for (long long int j = 2; j * j <= n; j ++)
    {
        if (n % j == 0)
        {
            return false;
        }
    }
    return true;
}

bool isSymm(long long int n)
{
    char num[20];
    sprintf(num, "%d", n);
    long long int length = strlen(num);
    for (long long int j = 0; j < length / 2; j++)
    {
        if (num[j] != num[length - 1 - j])
        {
            return false;
        }
    }
    return true;
}